#include <rclcpp/rclcpp.hpp>
#include <turtlebot_interfaces/srv/extinguish.hpp>
#include <memory>
#include <string>
#include <chrono>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

using namespace std::chrono_literals;

class ArduinoExtinguishServer : public rclcpp::Node
{
public:
    ArduinoExtinguishServer() : Node("arduino_extinguish_server"), serial_fd_(-1)
    {
        // 1. 시리얼 포트 초기화 (RPi4 기본 USB 포트 가정)
        init_serial_port("/dev/ttyUSB0", B115200);

        // 2. 서비스 서버 생성
        service_ = this->create_service<turtlebot_interfaces::srv::Extinguish>(
            "extinguish_fire",
            std::bind(&ArduinoExtinguishServer::handle_extinguish_request, this,
                      std::placeholders::_1, std::placeholders::_2));

        RCLCPP_INFO(this->get_logger(), "Arduino Extinguish Service Server is ready on /dev/ttyUSB0");
    }

    ~ArduinoExtinguishServer()
    {
        if (serial_fd_ != -1) {
            close(serial_fd_);
        }
    }

private:
    int serial_fd_;
    rclcpp::Service<turtlebot_interfaces::srv::Extinguish>::SharedPtr service_;

    void init_serial_port(const char* port_name, int baud_rate)
    {
        serial_fd_ = open(port_name, O_RDWR | O_NOCTTY | O_SYNC);
        if (serial_fd_ < 0) {
            RCLCPP_ERROR(this->get_logger(), "Error %i opening %s: %s", errno, port_name, strerror(errno));
            return;
        }

        struct termios tty;
        if (tcgetattr(serial_fd_, &tty) != 0) {
            RCLCPP_ERROR(this->get_logger(), "Error %i from tcgetattr", errno);
            return;
        }

        cfsetospeed(&tty, baud_rate);
        cfsetispeed(&tty, baud_rate);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
        tty.c_iflag &= ~IGNBRK;
        tty.c_lflag = 0;
        tty.c_oflag = 0;
        tty.c_cc[VMIN]  = 0;
        tty.c_cc[VTIME] = 1;

        tty.c_iflag &= ~(IXON | IXOFF | IXANY);
        tty.c_cflag |= (CLOCAL | CREAD);
        tty.c_cflag &= ~(PARENB | PARODD);
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr(serial_fd_, TCSANOW, &tty) != 0) {
            RCLCPP_ERROR(this->get_logger(), "Error %i from tcsetattr", errno);
        }

        // 보드 리셋 대기
        rclcpp::sleep_for(2s);
        tcflush(serial_fd_, TCIOFLUSH);
    }

    void handle_extinguish_request(
        const std::shared_ptr<turtlebot_interfaces::srv::Extinguish::Request> request,
        std::shared_ptr<turtlebot_interfaces::srv::Extinguish::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "Extinguish request received. Target Y: %.2f", request->y_val);

        if (serial_fd_ < 0) {
            RCLCPP_ERROR(this->get_logger(), "Serial port is not open.");
            response->success = 0;
            return;
        }

        tcflush(serial_fd_, TCIOFLUSH);

        // 1. y_val 값을 문자열로 변환하고 끝에 개행 문자(\n) 추가
        // 예: 15.5를 받으면 "15.500000\n" 형태로 전송됨
        std::string cmd_str = std::to_string(request->y_val) + "\n";
        write(serial_fd_, cmd_str.c_str(), cmd_str.length());

        RCLCPP_INFO(this->get_logger(), "Sent value '%s' to Arduino. Waiting for 'off'...", cmd_str.substr(0, cmd_str.length()-1).c_str());

        // 2. 아두이노로부터 "off" 응답 대기 (최대 10초 타임아웃)
        auto start_time = this->now();
        std::string buffer = "";
        bool task_finished = false;

        while ((this->now() - start_time).seconds() < 10.0) {
            char read_buf[16];
            memset(read_buf, 0, sizeof(read_buf));

            int num_bytes = read(serial_fd_, read_buf, sizeof(read_buf) - 1);
            if (num_bytes > 0) {
                buffer += read_buf;

                if (buffer.find("off") != std::string::npos) {
                    task_finished = true;
                    break;
                }
            }
            rclcpp::sleep_for(50ms);
        }

        // 3. 결과 반환
        if (task_finished) {
            RCLCPP_INFO(this->get_logger(), "Received 'off'. Extinguish action successful.");
            response->success = 1;
        } else {
            RCLCPP_WARN(this->get_logger(), "Timeout: Did not receive 'off' from Arduino.");
            response->success = 0;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArduinoExtinguishServer>());
    rclcpp::shutdown();
    return 0;
}
