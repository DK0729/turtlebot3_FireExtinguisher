#include <memory>
#include <string>
#include <chrono>

#include <vector>   // 배열 (Vector)
#include <utility>  // Pair 자료구조 사용을 위한 것.

//#include "geometry_msgs/msg/twist.hpp" // OpenCR 직접 명령
#include "geometry_msgs/msg/twist_stamped.hpp"

#include "nav_msgs/msg/odometry.hpp"

#include "visualization_msgs/msg/marker.hpp" // Rviz에 Marking을 하기 위함
#include "sensor_msgs/msg/laser_scan.hpp" // Lidar(Scan) 데이터를 받기 위함
#include <cmath> // std::asin, std::cos, std::sin 사용
#include <algorithm> // std::max, std::min 사용

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "std_msgs/msg/empty.hpp"
#include "std_msgs/msg/bool.hpp"
#include "nav2_msgs/action/spin.hpp" // Nav2 spin 명령 action
#include "nav2_msgs/action/navigate_to_pose.hpp"

#include "turtlebot_interfaces/srv/extinguish.hpp" //custom interfaces
#include "turtlebot_interfaces/msg/yolo.hpp" // yolo interfaces

#include "frontier_exploration_ros2/srv/control_exploration.hpp"
//frontier pkg from git

using namespace std::chrono_literals;

class ExplorationNode : public rclcpp::Node
{
public:
    enum State {
        STATE_0_INITIAL, 
        STATE_1_EXPLORE,        // SLAM + Nav2 + Frontier 자율 주행 
        STATE_2_STOP_AND_TWIST, // 정지 후 제자리 회전하며 불꽃 탐색
        STATE_3_MOVE_TO_FIRE,   // 불꽃 이동 및 조준 (좌우 균형 + 접근) (Nav2 Action 진행)
        STATE_4_EXTINGUISH      // 불 끄기 (Arduino Service 진행)
    };

    ExplorationNode() : Node("exploration_node"), current_state_(STATE_0_INITIAL)
    {
        // 1. Publisher & Subscriber
        
        // Enter 대신할 Topic subscriber : 
        trigger_sub_ = this->create_subscription<std_msgs::msg::Empty>(
            "toggle_exploration", 10,
            std::bind(&ExplorationNode::trigger_callback, this, std::placeholders::_1));

        // YOLO Topic Subscriber
        yolo_sub_ = this->create_subscription<turtlebot_interfaces::msg::Yolo>(
            "yolo_detection", rclcpp::QoS(10).best_effort(),
            std::bind(&ExplorationNode::yolo_callback, this, std::placeholders::_1));
            
        // Lidar Topic Subscriber
        lidar_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "scan", rclcpp::SensorDataQoS(), // Lidar는 주로 SensorDataQoS를 사용함
        std::bind(&ExplorationNode::lidar_callback, this, std::placeholders::_1));

        // 탐색 완료 이벤트 수신 위한 subscriber
        completion_sub_ = this->create_subscription<std_msgs::msg::Empty>(
            "exploration_complete", 10,
            std::bind(&ExplorationNode::completion_callback, this, std::placeholders::_1));   

        // Rviz marker publisher 추가
        marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("fire_marker", 10);

        //추가_publish_frontier_active 함수 작동 위해
        //선언 변수에 실제 토픽 이름과 큐 사이즈 할당, "frontier_active" 는 프로젝트 이름 맞게 수정
        frontier_pub_ = this->create_publisher<std_msgs::msg::Bool>("frontier_active", 10);
        frontier_client_ = this->create_client<frontier_exploration_ros2::srv::ControlExploration>(
            "control_exploration");

        // Odom 데이터 구독
        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "odom", rclcpp::SensorDataQoS(),
            std::bind(&ExplorationNode::odom_callback, this, std::placeholders::_1));
        
        // cmd_vel Publisher (수동 직진 제어용) : Action 직진 실패 시
        // cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel_teleop", 10);
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/cmd_vel", 10);

        // 2. Action & Service Client
        nav_client_ = rclcpp_action::create_client<nav2_msgs::action::NavigateToPose>(
            this, "navigate_to_pose");
        // Nav2의 이동 명령

        spin_client_ = rclcpp_action::create_client<nav2_msgs::action::Spin>(
            this, "spin");
        // Nav2의 회전 명령

        // 아두이노 Service Request
        arduino_client_ = this->create_client<turtlebot_interfaces::srv::Extinguish>(
            "extinguish_fire");
        
        RCLCPP_INFO(this->get_logger(), "Node Started, Waiting for Enter (State_0_INITIAL)");        
    }

private:
    State current_state_;
    float target_x_ = 0.0;
    float target_y_ = 0.0;
    
    sensor_msgs::msg::LaserScan::SharedPtr latest_scan_ = nullptr;

    // For Exploration node -> OpenCR
    float fallback_drive_dist_ = 0.0; // 실패 시 수동으로 갈 거리를 저장할 변수
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_vel_pub_;
    rclcpp::TimerBase::SharedPtr drive_timer_;
    bool is_fallback_driving_ = false; // 수동 주행 중인지 체크하는 플래그

    int fallback_ticks_ = 0;
    int max_fallback_ticks_ = 0;
    //
    float target_angle_rad = 0.0;
    float camera_fov_rad = 41.0 * M_PI / 180.0; // 카메라 화각(44도)을 라디안으로 변환
    
    bool is_final_alignment_ = false;

    // [추가] YOLO 신호 일시 소실 및 정지 제어용 변수
    bool yolo_signal_lost_ = false;    // 현재 신호가 끊겨서 대기(정지) 중인지 나타내는 플래그
    rclcpp::Time last_fire_seen_time_; // 마지막으로 불꽃을 정상적으로 인식한 시간
    double yolo_timeout_sec_ = 2.0;    // 다시 신호가 들어올 때까지 기다려줄 유예 시간 (2초)


    bool is_navigating_straight_ = false;
    // timer
    rclcpp::TimerBase::SharedPtr transition_timer_;

    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr trigger_sub_;
    rclcpp_action::Client<nav2_msgs::action::NavigateToPose>::SharedPtr nav_client_;
    rclcpp::Client<turtlebot_interfaces::srv::Extinguish>::SharedPtr arduino_client_;
    rclcpp_action::Client<nav2_msgs::action::Spin>::SharedPtr spin_client_;
    rclcpp::Subscription<turtlebot_interfaces::msg::Yolo>::SharedPtr yolo_sub_;

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr lidar_sub_; //Lidar 구독자 선언
    rclcpp::Client<frontier_exploration_ros2::srv::ControlExploration>::SharedPtr frontier_client_; // Frontier
    rclcpp::TimerBase::SharedPtr explore_timer_; // Frontier
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr frontier_pub_; // Frontier 추가_클래스 맴버 변수 선언
    rclcpp::TimerBase::SharedPtr state_2_timer_; // state2 Timer 변수 선언
    rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr completion_sub_;//log_맴버 변수 선언
    
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_; // Marking 할 publisher

    rclcpp::TimerBase::SharedPtr arduino_timeout_timer_;
    rclcpp::TimerBase::SharedPtr escape_timer_;
    // Marking 하기 위해 사용되는 좌표
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    
    // [추가] 불 끄는 동안 자세를 유지하기 위한 실시간 보정 타이머
    rclcpp::TimerBase::SharedPtr stabilize_timer_;

    float robot_odom_x_ = 0.0;
    float robot_odom_y_ = 0.0;
    float robot_yaw_ = 0.0;

    // ==========================================
    std::vector<std::pair<float, float>> rviz_marked_positions_;

    bool is_already_marked(float current_x, float current_y) {
        // std::vector 와 밑의 반복문을 통해 만일 비어있으면 바로 return 한다.
        for (const auto& pos : rviz_marked_positions_) {
            float dx = current_x - pos.first;
            float dy = current_y - pos.second;
            // pos.first와 pos.second는 이전에 저장해두었던 절대 좌표계이다.

            float distance = std::sqrt(dx * dx + dy * dy);
            // 센서의 오차를 0.5m 이내로 설정한다. 

            if (distance < 1.0) { // 0.5m 이내면 이미 Rviz에 마킹했던 양초로 간주
                return true; 
            }
        }
        return false;
    }

// ===========================
// < 상태 전이 함수 >
// ===========================

// 클래스 내부 적절한 위치에 추가
void completion_callback(const std_msgs::msg::Empty::SharedPtr)
{
    // 자율 주행 중(1)일 때 신호가 오면 작동
    if (current_state_ == STATE_1_EXPLORE) {
        // 요청하신 로그 문구 출력
        RCLCPP_INFO(this->get_logger(), "Since we filled unknown area, frontier node shutdowned. State 0.");
       
        // 상태를 0(INITIAL)으로 돌려 로봇을 멈춤
        transition_to(STATE_0_INITIAL);
    }
}

// Odom 데이터 수신 및 절대 위치/방향 계산
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        robot_odom_x_ = msg->pose.pose.position.x;
        robot_odom_y_ = msg->pose.pose.position.y;
        
        double qx = msg->pose.pose.orientation.x;
        double qy = msg->pose.pose.orientation.y;
        double qz = msg->pose.pose.orientation.z;
        double qw = msg->pose.pose.orientation.w;
        // 쿼터니안을 우리가 아는 라디안(Yaw) 각도로 변환
        robot_yaw_ = std::atan2(2.0 * (qw * qz + qx * qy), 1.0 - 2.0 * (qy * qy + qz * qz));
    }

void transition_to(State next_state)
    {
        if (current_state_ == next_state) return;
        current_state_ = next_state;

        switch (current_state_) {
            case STATE_0_INITIAL:
                RCLCPP_INFO(this->get_logger(), "State: INITIAL. Stopping everything. State 0.");
                
                // Fronteir 자체의 OFF도 해야 한다. +) Fronteir OFF 노드 내에 Cancel 명령이 포함됨.
                stop_frontier_exploration();
                nav_client_->async_cancel_all_goals(); // Exploration node -> Nav2의 주행 명령을 취소하라는 것. (양초를 찾으러 가는 길일 수 있다.)
                spin_client_->async_cancel_all_goals(); // Exploration -> Nav2의 Twist 명령을 취소한다.
                break;

            case STATE_1_EXPLORE:
                RCLCPP_INFO(this->get_logger(), "State: EXPLORE. Starting Frontier! State 1.");
                // State 2에서 넘어온 회전(Spin) Action을 확실히 끊는다.
                spin_client_->async_cancel_all_goals();
                //기존에 작동 중인 타이머 있으면 종료
                if (explore_timer_ && !explore_timer_->is_canceled()) {
                    explore_timer_->cancel();
                }

                // Frontier 시작
                start_frontier_exploration();
                // 10초 STATE_2로 넘어가는 타이머 가동
                explore_timer_ = this->create_wall_timer(
                    std::chrono::seconds(10),
                    [this]() {
                        this->explore_timer_->cancel();
                        // *** Fronteir 에서 Nav2로 Cancel 명령이 필요하다. - Fronteir에서 사전에 Nav2로 보낸 명령을 취소하기 위함.
                        // *** Fronteir 자체의 OFF도 해야 한다. - Fronteir에서 Nav2로 더이상 Action 명령을 주지 않도록 하기 위함. - 내부적으로 Action Cancel에 관한 것도 포함되어 있다.
                        // 이미 취소했기에 State 3 이전에 가는 것은 취소하지 않아도 된다.
                        //frontier 중지
                        stop_frontier_exploration();
                        // 10초 후에는 STATE_2_STOP_AND_TWIST
                        this->transition_to(STATE_2_STOP_AND_TWIST);
                    });
                    break;

            case STATE_2_STOP_AND_TWIST: {
                RCLCPP_INFO(this->get_logger(), "State: STOP & TWIST. Looking for fire.");
                
                if (!spin_client_->wait_for_action_server(2s)) {
                    RCLCPP_ERROR(this->get_logger(), "Nav2 Spin action server unavailable.");
                    transition_to(STATE_1_EXPLORE); // 실패 시 다시 탐색으로 복귀
                    break;
                }
                
                auto spin_goal = nav2_msgs::action::Spin::Goal();
                spin_goal.target_yaw = 2.0 * M_PI; // 360도 회전

                auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::Spin>::SendGoalOptions();
                  
                send_goal_options.result_callback = 
                    std::bind(&ExplorationNode::spin_result_callback, this, std::placeholders::_1);

                // Nav2로 회전 명령 비동기 송신
                spin_client_->async_send_goal(spin_goal, send_goal_options);
                RCLCPP_INFO(this->get_logger(), "Spin Goal Sent: 360 degrees");

                state_2_timer_ = this->create_wall_timer(
                //this->create_wall_timer( A , B ) A라는 시간마다, B를 실행해라.
                std::chrono::milliseconds(20000), //20.00초 뒤에 실행되는 주기적인 함수
                [this]() {
                    this->state_2_timer_->cancel();
                    // 12.56초가 지났는데도 여전히 STATE_2에 머물러 있을 때 (YOLO 미발견)
                    if (this->current_state_ == STATE_2_STOP_AND_TWIST) {
                        RCLCPP_INFO(this->get_logger(), "Turned 360 degrees. No fire. Returning to State : 1.");
                        this->transition_to(STATE_1_EXPLORE); // STATE_1으로 복귀
                    }
                });

                break;
            }

            case STATE_3_MOVE_TO_FIRE: {
            RCLCPP_INFO(this->get_logger(), "State: MOVE TO FIRE. Approaching... State : 3");
    
            // 1. 현재 돌고 있는 스핀을 멈춤
            spin_client_->async_cancel_all_goals();

            // 2. 2초 대기 후 이동 로직 실행 (안정화 시간 확보)
            // transition_timer_를 사용하여 비동기 대기
            transition_timer_ = this->create_wall_timer(2000ms, [this]()
            {
                this->transition_timer_->cancel(); // 타이머 종료

                this->execute_incremental_align(false);

                });

                break; 
            }
            case STATE_4_EXTINGUISH:
            
                RCLCPP_INFO(this->get_logger(), "State : 4 - EXTINGUISH. Requesting Arduino.");
            // 2초 대기 후 아두이노로 명령 전송
                transition_timer_ = this->create_wall_timer(2000ms, [this]()
                {
                    this->transition_timer_->cancel(); // 타이머 끄기

                    // 정지 후 완전히 안정된 상태에서 거리를 재고 아두이노를 호출.
                    float current_dist = this->get_distance_to_candle(this->target_x_);
                    this->mark_fire_on_rviz(current_dist, 0.0);
                    this->send_arduino_request(); 
                });                         
                break;
            }
    }
    // =======================================================================
    // Callback 함수
    // =======================================================================


    // --- [이벤트] Keyboard Enter 입력 대용 : 새로운 Terminal에서 publish 해야 한다. (로봇 작동 시작 및 중지) ---
    void trigger_callback(const std_msgs::msg::Empty::SharedPtr)
    {
        // 1. 대기 상태 -> 탐색 시작
        if (current_state_ == STATE_0_INITIAL) {
            RCLCPP_INFO(this->get_logger(), "Start Exploration!!! State -> 1");
            transition_to(STATE_1_EXPLORE);
            }
        // 2. 탐색 상태 -> 종료 상태
            else {
            RCLCPP_INFO(this->get_logger(), "Finish. State -> 0");
            transition_to(STATE_0_INITIAL);
        }
    }

    // --- [이벤트] YOLO 데이터 수신 ---
    void yolo_callback(const turtlebot_interfaces::msg::Yolo::SharedPtr msg)
    {
        if (current_state_ == STATE_1_EXPLORE || 
            current_state_ == STATE_0_INITIAL || 
            is_fallback_driving_ || is_navigating_straight_) return;
        
// 1. YOLO 불꽃 신호 소실 (-999) 처리
    if (msg->x < -160) {
        if (current_state_ == STATE_3_MOVE_TO_FIRE) {
            if (!yolo_signal_lost_) {
                // [최초 소실 순간] 플래그를 켜고 로봇을 즉시 물리적으로 정지시킴
                yolo_signal_lost_ = true;
                last_fire_seen_time_ = this->now();
                
                // 현재 진행 중인 찔끔 회전(Spin) 및 직진(Nav2) 명령을 모두 취소 (로봇 정지)
                spin_client_->async_cancel_all_goals();
                nav_client_->async_cancel_all_goals();
                
                RCLCPP_WARN(this->get_logger(), "YOLO Signal Lost! Stopping robot immediately and waiting...");
            } else {
                // [정지 후 대기 상태] 유예 시간 초과 여부 검사
                double elapsed_time = (this->now() - last_fire_seen_time_).seconds();
                
                if (elapsed_time > yolo_timeout_sec_) {
                    RCLCPP_ERROR(this->get_logger(), "YOLO Timeout (%.1f s) exceeded. Giving up and returning to EXPLORE.", yolo_timeout_sec_);
                    yolo_signal_lost_ = false; // 플래그 리셋
                    transition_to(STATE_1_EXPLORE);
                } else {
                    // 유예 시간 안쪽이면 제자리에 멈춘 채 로그만 출력
                    RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, 
                        "Waiting for YOLO recovery... (Elapsed: %.1f / %.1f s)", elapsed_time, yolo_timeout_sec_);
                }
            }
        }
        return;
    }
// 2. YOLO 신호가 정상적으로 들어오는 경우 처리
        if (current_state_ == STATE_3_MOVE_TO_FIRE && yolo_signal_lost_) {
        // 제자리에 멈춰서 대기하던 중 신호가 다시 복구된 상황!
        RCLCPP_INFO(this->get_logger(), "YOLO Signal RECOVERED! Resuming incremental alignment.");
        yolo_signal_lost_ = false; // 플래그 해제
        
        // 들어온 신호로 타겟 좌표를 업데이트하고 멈췄던 정렬 루프 재가동
        target_x_ = msg->y;
        target_y_ = msg->x;
        execute_incremental_align(is_final_alignment_);
        return;
        }
            // 일반적인 상태 업데이트

            target_x_ = msg->y;
            target_y_ = msg->x;
        
            if (current_state_ == STATE_2_STOP_AND_TWIST) {
            
            float current_dist = get_distance_to_candle(target_x_);

            // 로봇의 현재 위치(robot_odom) + 로봇이 바라보는 방향(robot_yaw) + 촛불이 틀어진 각도
            float temp_angle_rad = -target_x_ * (camera_fov_rad / 320.0);
            float check_x = robot_odom_x_ + current_dist * std::cos(robot_yaw_ + temp_angle_rad);
            float check_y = robot_odom_y_ + current_dist * std::sin(robot_yaw_ + temp_angle_rad);

            // 마킹 여부 검사
            if (is_already_marked(check_x, check_y) && current_state_ != STATE_4_EXTINGUISH) {
                // 이미 꺼진 촛불이라면 무시하고 그대로 회전을 계속 진행함 (return)
                RCLCPP_INFO(this->get_logger(), "Already Fire Detected! Pass it");
                return; 
            }

            if (state_2_timer_) { 
                state_2_timer_->cancel(); 
            } // 위에서 설정해둔 timer를 제거한다.
            transition_to(STATE_3_MOVE_TO_FIRE);
        }
        
    }
// --- [이벤트] Lidar 데이터 수신 ---    
    void lidar_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
       latest_scan_ = msg;
    }

// ★ [새로 추가] Spin Action 결과를 받아서 고착(Failed) 시 탈출하는 콜백
void spin_result_callback(const rclcpp_action::ClientGoalHandle<nav2_msgs::action::Spin>::WrappedResult & result)
    {
        // 성공(SUCCEEDED)했거나, 현재 상태가 STATE_2가 아니면 아무것도 안 함
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED || current_state_ != STATE_2_STOP_AND_TWIST) {
            return;
        }

        // Action이 Failed 되거나 Aborted 났을 때 (어딘가에 끼어서 고착됨)
        RCLCPP_WARN(this->get_logger(), "Spin Action Failed! Activating Frontier for 5s to escape...");

        // 1. 진행 중이던 기존 20초 타이머 정지
        if (state_2_timer_) {
            state_2_timer_->cancel();
        }

        // 2. 5초간 Frontier를 가동하여 갇힌 곳 빠져나오기
    execute_escape_backward(0.2);
    }
//=====================================
// --- State 4 에서 사용할 함수 모음 ---
float get_distance_to_candle(float yolo_pixel_x)
{
    if (!latest_scan_) 
    {
        RCLCPP_INFO(this->get_logger(), "Warning : Lidar Disable !!");
        return 1.0; 
    }    

    // 1. 픽셀 -> 라디안 변환 및 LiDAR 180도(M_PI) 역방향 보정
    float angle_rad = (-yolo_pixel_x * (camera_fov_rad / 320.0)) + M_PI;
    
    // 각도가 -PI ~ PI 범위를 넘어가면 표준 범위로 정규화
    while (angle_rad > M_PI) angle_rad -= 2.0 * M_PI;
    while (angle_rad < -M_PI) angle_rad += 2.0 * M_PI;

    // 2. 인덱스 계산 및 배열 크기 확인
    int num_ranges = latest_scan_->ranges.size();
    int index = (angle_rad - latest_scan_->angle_min) / latest_scan_->angle_increment;

    float min_dist = 10.0; 
    int search_range = 10;  // 좌우 10칸 탐색

    // 3. 좌우 탐색 (모듈러 연산 '%'을 사용하여 코드를 대폭 단축)
    for (int i = -search_range; i <= search_range; i++) {
        // 음수 인덱스 방지를 위해 num_ranges를 더하고 나머지를 구함 (깔끔한 순환 배열 처리)
        int check_idx = (index + i + num_ranges) % num_ranges;
        float d = latest_scan_->ranges[check_idx];
        
        // 0.13m 이상이고 최솟값 갱신 시
        if (d > 0.13 && d < min_dist && std::isfinite(d)) {
            min_dist = d;
        }
    }

    // 만약 양초를 못 찾아서 10.0 그대로라면 안전하게 0.3 반환, 아니면 찾은 최솟값 반환
    float exact_distance = (min_dist >= 10.0) ? 0.3 : min_dist;

    RCLCPP_INFO(this->get_logger(), "Exact candle distance: %.2f m", exact_distance);
    return exact_distance;
}
void mark_fire_on_rviz(float lidar_distance, float yolo_pixel_x)
    {   
        // 1. 각도 및 로봇 기준 상대 좌표 계산
        target_angle_rad = -yolo_pixel_x * (camera_fov_rad / 320.0);
  
        // 2. RViz에 그리기 위한 맵 기준 절대 좌표 계산
        float abs_x = robot_odom_x_ + lidar_distance * std::cos(robot_yaw_ + target_angle_rad);
        float abs_y = robot_odom_y_ + lidar_distance * std::sin(robot_yaw_ + target_angle_rad);
        
        // 배열에 방금 끈 불꽃의 절대 좌표를 저장.
        rviz_marked_positions_.push_back({abs_x, abs_y});

        // 3. RViz 마커 생성 및 설정
        auto marker = visualization_msgs::msg::Marker();
        marker.header.frame_id = "map"; // map 절대 좌표계 기준
        marker.header.stamp = this->now();
        marker.ns = "candle_target";
        marker.id = rviz_marked_positions_.size();

        marker.type = visualization_msgs::msg::Marker::CYLINDER; // 원기둥 모양
        marker.action = visualization_msgs::msg::Marker::ADD;

        // 방금 계산한 x, y 좌표에 마커 배치
        marker.pose.position.x = abs_x;
        marker.pose.position.y = abs_y;
        marker.pose.position.z = 0.5; 

        // 마커 크기 (가로 10cm, 세로 10cm, 높이 40cm)
        marker.scale.x = 0.1;
        marker.scale.y = 0.1;
        marker.scale.z = 0.4;

        // 마커 색상 (빨간색)
        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0f; // 불투명도 100%

        // 5. 토픽 퍼블리시
        marker_pub_->publish(marker);
        RCLCPP_INFO(this->get_logger(), "RViz Marker Published at x: %.2f, y: %.2f", abs_x, abs_y);
    }
    
    void send_nav_goal_state(float lidar_distance)
    {
        if (!nav_client_->wait_for_action_server(2s)) {
            RCLCPP_ERROR(this->get_logger(), "Nav2 Action server unavailable.");
            transition_to(STATE_1_EXPLORE);
            return;
        }

        // [중요] 안전 거리 0.3m (Nav2 코스트맵 충돌 회피)
        float stop_margin = 0.35; 
        float total_move_dist = lidar_distance - stop_margin;

        if (total_move_dist <= 0.25) {
            RCLCPP_INFO(this->get_logger(), "Already close enough (%.2f m). Skipping movement.", lidar_distance);
            this->execute_incremental_align(true);
            return;
        }
        // 한 번에 가지 않고, 0.2m 씩 끊어서 이동
        float move_dist = std::min(total_move_dist, 0.25f);
        // 2. 만약 Nav2가 거부할 경우를 대비해, 가야 할 거리를 미리 저장.
        fallback_drive_dist_ = move_dist;

        // [추가] 직진 기동 시작을 알림
        is_navigating_straight_ = true;

        // Nav2 Goal 메시지 생성
        auto goal_msg = nav2_msgs::action::NavigateToPose::Goal();
        
        // base_link(로봇 기준 상대 좌표)를 사용.
        goal_msg.pose.header.frame_id = "base_link"; 
        goal_msg.pose.header.stamp = this->now();
        
        // 로봇 정면(x축)으로 move_dist 만큼 직진
        goal_msg.pose.pose.position.x = move_dist;
        goal_msg.pose.pose.position.y = 0.0;
        goal_msg.pose.pose.position.z = 0.0;

        // 회전 없이 정면 유지 (z=0, w=1)
        goal_msg.pose.pose.orientation.x = 0.0;
        goal_msg.pose.pose.orientation.y = 0.0;
        goal_msg.pose.pose.orientation.z = 0.0;
        goal_msg.pose.pose.orientation.w = 1.0;

        // Action 전송 및 Callback 설정
        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::NavigateToPose>::SendGoalOptions();
        send_goal_options.result_callback = 
            std::bind(&ExplorationNode::goal_result_callback, this, std::placeholders::_1);
        
        RCLCPP_INFO(this->get_logger(), "Sending Nav2 Goal (base_link): Forward %.2f m", move_dist);
        nav_client_->async_send_goal(goal_msg, send_goal_options);
    }
    


// --- [이벤트] 불 끄기 완료 (Arduino Service 응답) ---
void service_response_callback(rclcpp::Client<turtlebot_interfaces::srv::Extinguish>::SharedFuture future)
    {
        if (current_state_ != STATE_4_EXTINGUISH) return;

    // 1. 아두이노 응답 대기용 시한폭탄 해제
    if (arduino_timeout_timer_ && !arduino_timeout_timer_->is_canceled()) {
        arduino_timeout_timer_->cancel();
    }
    // ★ 2. [핵심 추가] 좌우로 훑던 Sweep 타이머 확실하게 종료!
    if (stabilize_timer_ && !stabilize_timer_->is_canceled()) {
        stabilize_timer_->cancel();
    }

    // ★ 3. 타이머들을 다 껐으니, 마지막으로 확실하게 물리적 브레이크(0.0) 밟기
    auto stop_msg = geometry_msgs::msg::TwistStamped();
    stop_msg.header.stamp = this->now();
    stop_msg.header.frame_id = "base_link";
    stop_msg.twist.angular.z = 0.0;
    this->cmd_vel_pub_->publish(stop_msg);

    auto response = future.get();
    if (response->success == 1) {
        RCLCPP_INFO(this->get_logger(), "[REAL FIRE] Extinguish Complete! Good Job!");
    } else {
        RCLCPP_WARN(this->get_logger(), "[FAKE FIRE] Ignored Fake Fire. Moving On!");
    }

    transition_to(STATE_1_EXPLORE);
    }

// ===================================
// --- 하위 헬퍼 함수들 (비동기 송신용) ---
// ===================================

void goal_result_callback(const rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateToPose>::WrappedResult & result)
{   
    // [추가] 직진 기동이 끝났으므로 플래그 해제
        is_navigating_straight_ = false;
    if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
        RCLCPP_INFO(this->get_logger(), "Nav2 Goal Reached! Ready to extinguish.");
        is_fallback_driving_ = false; // 정상 도착했으니 플래그 0
    } else {
            // [수정] CANCELED 예외처리 삭제하고 실패 시 바로 수동 주행으로 가도록 롤백
            RCLCPP_WARN(this->get_logger(), "Nav2 Goal Aborted. Forcing fallback drive!");
            is_fallback_driving_ = true;  
            execute_fallback_drive(fallback_drive_dist_);
        }
        transition_timer_ = this->create_wall_timer(2000ms, [this]() {
        this->transition_timer_->cancel();
            
            if (!this->is_fallback_driving_ && this->current_state_ == STATE_3_MOVE_TO_FIRE) {
                // ★ [핵심 수정] 직진 후 남은 거리를 다시 측정
                float current_dist = this->get_distance_to_candle(this->target_x_);
                
                // 남은 거리가 안전거리(0.3m)를 제외하고도 0.15m 이상 남았다면 다시 1차 정렬 반복!
                if (current_dist - 0.35 > 0.15) {
                    RCLCPP_INFO(this->get_logger(), "Still far (%.2f m). Re-aligning and moving again...", current_dist);
                    this->execute_incremental_align(false); // 1차 정렬 후 다시 이동
                } else {
                    RCLCPP_INFO(this->get_logger(), "Close enough (%.2f m). Starting Final Alignment.", current_dist);
                    this->execute_incremental_align(true);  // 충분히 가까우면 최종 정렬
                }
            }
        });
}

void start_frontier_exploration() 
{
    if (!frontier_client_->wait_for_service(2s)) {
        RCLCPP_ERROR(this->get_logger(),
                     "Frontier service unavailable");
        return;
    }

// wait for service (서비스가 늦게 뜰 수도 있어서 2s 기다리는 것) Vs service is ready는 기다리면 밀릴 수 있으니까 뒤에게 망가질 수 있기 때문. 
// true false만 확인하기 때문에 안 기다린다. (Launch 할 때 오류가 생기면 문제가 생길 수 있음) 

    auto request =
        std::make_shared<
            frontier_exploration_ros2::srv::ControlExploration::Request>();

    request->action =
        frontier_exploration_ros2::srv::ControlExploration::Request::ACTION_START;

    request->delay_seconds = 0.0;
    request->quit_after_stop = false;

    frontier_client_->async_send_request(request);

    RCLCPP_INFO(this->get_logger(),
                "Frontier exploration started");
}

void stop_frontier_exploration() //추가
{
    if (!frontier_client_->wait_for_service(2s)) {
        RCLCPP_ERROR(this->get_logger(),
                     "Frontier control service unavailable.");
        return;
    }

    auto request =
        std::make_shared<frontier_exploration_ros2::srv::ControlExploration::Request>();

    request->action =
        frontier_exploration_ros2::srv::ControlExploration::Request::ACTION_STOP;

    request->delay_seconds = 0.0;
    request->quit_after_stop = false;

    frontier_client_->async_send_request(request);

    RCLCPP_INFO(this->get_logger(),
                "Frontier exploration stopped.");
}

    void send_arduino_request()
    {
        if (!arduino_client_->wait_for_service(2s)) {
            RCLCPP_ERROR(this->get_logger(), "Arduino Service unavailable.");
            transition_to(STATE_1_EXPLORE);
            return;
        }

        auto request = std::make_shared<turtlebot_interfaces::srv::Extinguish::Request>();
        request->y_val = target_y_;

        arduino_client_->async_send_request(
            request,
            std::bind(&ExplorationNode::service_response_callback, this, std::placeholders::_1)
        );
        // 아두이노 응답 무한 대기 방지용 타임아웃 (5초)
        arduino_timeout_timer_ = this->create_wall_timer(5000ms, [this]() {
            this->arduino_timeout_timer_->cancel();
            if (this->current_state_ == STATE_4_EXTINGUISH) {
                RCLCPP_ERROR(this->get_logger(), "Arduino Service Timeout! Forcing transition.");
                this->transition_to(STATE_1_EXPLORE);
            }
        });
    }

    // --- [이벤트] 2차 정렬(최종 조준)완료 ---
    void final_align_result_callback(const rclcpp_action::ClientGoalHandle<nav2_msgs::action::Spin>::WrappedResult & result)
    {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(this->get_logger(), "Final Alignment Complete! Ready to Extinguish.");
            // 두 번의 정렬과 이동이 모두 끝났으므로 최종적으로 불 끄기 돌입!
            transition_to(STATE_4_EXTINGUISH);
        }   else {
            RCLCPP_ERROR(this->get_logger(), "Final Alignment Failed! Returning to explore.");
            transition_to(STATE_1_EXPLORE);
        }
    }
    // --- 수동 직진 (OpenCR 제어) ---
    void execute_fallback_drive(float dist)
    {
        if (drive_timer_ && !drive_timer_->is_canceled()) {
            drive_timer_->cancel();
        }

        float speed = 0.35; // 0.35 m/s 속도로 전진
        float duration = dist / speed; 
        
        fallback_ticks_ = 0;
        max_fallback_ticks_ = std::ceil(duration / 0.1); 

        RCLCPP_INFO(this->get_logger(), "Starting Fallback Drive for %.2f seconds (%d ticks).", duration, max_fallback_ticks_);

        drive_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            [this, speed]() {
                if (this->fallback_ticks_ < this->max_fallback_ticks_) {
                    auto twist_msg = geometry_msgs::msg::TwistStamped();
                    twist_msg.header.stamp = this->now();
                    twist_msg.header.frame_id = "base_link"; // 로봇 기준
                    twist_msg.twist.linear.x = speed;
                    
                    this->cmd_vel_pub_->publish(twist_msg);
                    this->fallback_ticks_++;
                } 
                else {
                    this->drive_timer_->cancel(); 
                    
                    // 정지(브레이크) 명령도 Stamped로 쏘기
                    auto stop_msg = geometry_msgs::msg::TwistStamped();
                    stop_msg.header.stamp = this->now();
                    stop_msg.header.frame_id = "base_link";
                    stop_msg.twist.linear.x = 0.0;
                    
                    this->cmd_vel_pub_->publish(stop_msg); 
                    
                    RCLCPP_INFO(this->get_logger(), "Drive Complete! Ready to extinguish.");
                    this->is_fallback_driving_ = false; 

                    if (this->current_state_ == STATE_3_MOVE_TO_FIRE) {
                        this->transition_timer_ = this->create_wall_timer(2000ms, [this]() {
                            this->transition_timer_->cancel();
                            
                            // ★ [수정] 수동 주행 후에도 남은 거리를 확인하여 쪼개기 반영
                            float current_dist = this->get_distance_to_candle(this->target_x_);
                            if (current_dist - 0.35 > 0.15) {
                                this->execute_incremental_align(false);
                            } else {
                                this->execute_incremental_align(true);
                            }
                        });
                }
            }
        });
    }

// --- [새로 추가] 고착 시 강제 후진 (Nav2 무시하고 cmd_vel 직접 제어) ---
    void execute_escape_backward(float dist)
    {
        if (drive_timer_ && !drive_timer_->is_canceled()) {
            drive_timer_->cancel();
        }

        float speed = -0.15; // 뒤로 가야 하므로 마이너스(-) 속도
        float duration = dist / std::abs(speed); 
        
        fallback_ticks_ = 0;
        max_fallback_ticks_ = std::ceil(duration / 0.1); 

        RCLCPP_WARN(this->get_logger(), "Forcing backward drive for %.2f m to escape!", dist);

        drive_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            [this, speed]() {
                if (this->fallback_ticks_ < this->max_fallback_ticks_) {
                    auto twist_msg = geometry_msgs::msg::TwistStamped();
                    twist_msg.header.stamp = this->now();
                    twist_msg.header.frame_id = "base_link"; 
                    twist_msg.twist.linear.x = speed; // 후진 명령
                    
                    this->cmd_vel_pub_->publish(twist_msg);
                    this->fallback_ticks_++;
                } 
                else {
                    this->drive_timer_->cancel(); 
                    
                    // 정지(브레이크)
                    auto stop_msg = geometry_msgs::msg::TwistStamped();
                    stop_msg.header.stamp = this->now();
                    stop_msg.header.frame_id = "base_link";
                    stop_msg.twist.linear.x = 0.0;
                    
                    this->cmd_vel_pub_->publish(stop_msg); 
                    
                    RCLCPP_INFO(this->get_logger(), "Escape Complete! Returning to EXPLORE.");
                    
                    // 후진으로 공간을 확보했으니, 다시 프론티어 탐색(State 1)으로 안전하게 복귀
                    this->transition_to(STATE_1_EXPLORE);
                }
            });
    }

    void execute_incremental_align(bool is_final)
    {
        is_final_alignment_ = is_final;
        perform_next_spin_step();
    }

    void perform_next_spin_step()
    {
        // 1. 반복문 탈출 조건: YOLO 정중앙(오차 1 픽셀 이내)에 위치했는지 확인
        if (std::abs(target_x_) <= 2.0) {
            if (!is_final_alignment_) {   
                // [수정] 정렬 성공 시에도 마지막 target_x_ 값을 찍어줌
                RCLCPP_INFO(this->get_logger(), "1st Alignment Centered! (target_x: %.1f) Moving forward to the fire.", target_x_);
                // 정면을 바라보게 되었으므로 get_distance_to_candle에 0.0 대입 후 직진
                float final_dist = get_distance_to_candle(target_x_); 
                send_nav_goal_state(final_dist);
            } else {
                RCLCPP_INFO(this->get_logger(), "Final Alignment Centered! (target_x: %.1f) Ready to Extinguish.", target_x_);
                transition_to(STATE_4_EXTINGUISH);
            }
            return; // 중앙에 왔으므로 Nav2 Action을 쏘지 않고 반복문(재귀)을 탈출합니다.
        }

        // 2. 정중앙이 아니면 Nav2 Action에게 찔끔 회전하라고 명령 전송
        // 부호 결정: target_x_가 양수면 좌측(-), 음수면 우측(+)으로 돌도록 세팅
        float step_rad = (target_x_ > 0) ? -0.000002 : 0.000002; 

        auto spin_goal = nav2_msgs::action::Spin::Goal();
        spin_goal.target_yaw = step_rad;

        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::Spin>::SendGoalOptions();
        
        // ★ Action이 Succeed 되면 'spin_step_result_callback'을 호출하여 다시 루프를 돌게 만듦
        send_goal_options.result_callback = 
            std::bind(&ExplorationNode::spin_step_result_callback, this, std::placeholders::_1);

        spin_client_->async_send_goal(spin_goal, send_goal_options);
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, 
            "Sending incremental Spin Action: %.3f rad (YOLO target_x: %.1f)", step_rad, target_x_);
    
    }

    void spin_step_result_callback(const rclcpp_action::ClientGoalHandle<nav2_msgs::action::Spin>::WrappedResult & result)
    {
        // Action Succeed를 받으면, 다시 함수를 호출하여 (반복문) YOLO 좌표를 검사하고 또 돕니다!
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            if (!yolo_signal_lost_) {
                // [수정] 성공하자마자 바로 다음 스텝을 밟지 않고, 0.5초(500ms) 대기 타이머를 구동합니다.
                // 로봇이 회전을 멈춘 상태에서 YOLO가 최신 카메라 프레임을 받아 target_x_를 갱신할 물리적 시간을 벌어줍니다.
                transition_timer_ = this->create_wall_timer(500ms, [this]() {
                    this->transition_timer_->cancel(); // 일회성 타이머이므로 즉시 취소
                    this->perform_next_spin_step();    // 0.5초 뒤 갱신된 안전한 target_x_ 값으로 다음 정렬 판단
                });
            }
        } else if (result.code == rclcpp_action::ResultCode::CANCELED && yolo_signal_lost_) {
            RCLCPP_INFO(this->get_logger(), "Incremental Spin Action canceled for waiting. Robot paused.");
        }
        else {
            RCLCPP_ERROR(this->get_logger(), "Incremental Alignment Failed! Returning to explore.");
            transition_to(STATE_1_EXPLORE);
        }
    }

};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ExplorationNode>();
    rclcpp::spin(node); 
    rclcpp::shutdown();
    return 0;
}
