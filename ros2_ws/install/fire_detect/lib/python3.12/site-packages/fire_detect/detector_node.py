import rclpy
import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO as YOLOModel
from turtlebot_interfaces.msg import Yolo as YOLOMsg
from rclpy.qos import QoSProfile, ReliabilityPolicy

class FireDetectorNode(Node):
    def __init__(self):
        super().__init__('fire_detector_node')
        
        #QoS 설정 
        qos_profile = QoSProfile(
            depth=3,
            reliability=ReliabilityPolicy.BEST_EFFORT)
        
        self.get_logger().info('sub create start')   # 코드 실행 여부를 확인하기 위한 코드
        
        # 카메라 pub.node (reliability) -> PC sub.node (best effort)
        # pub에서 준 data가 일정 부분 손실해도 진행
        self.subscription = self.create_subscription(
            Image,
            '/image_raw', 
            self.image_callback,
            qos_profile 
        )
        
        self.get_logger().info('subscription create success')   # 코드 실행 여부를 확인하기 위한 코드
        
        self.image_pub = self.create_publisher(
            Image,
            '/fire_detect_image', 
            10
        )
        
        self.pos_pub= self.create_publisher(
            YOLOMsg,
            '/yolo_detection',
            10 
        )
        
        self.fire_frame_cnt = 0
        self.bridge = CvBridge()
        self.model = YOLOModel('/home/donggwan/ros2_ws/fire_detect_package/fire_detect_yolov8n-13/weights/best.pt')
        
        self.get_logger().info('Waiting real-world image...')

    def image_callback(self, msg):
        try:
            # ROS2 메시지 형식을 OpenCV(BGR) 이미지로 변환 (image message -> cv2)
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'이미지 변환 실패: {e}')
            return

        # 터틀봇에 모델 성능 조정
        # 크기 : 320pixel, conf >= 0.25일 때 불로 인식하고 bbox 생성
        results = self.model(cv_image, imgsz=320, conf=0.15, verbose=False)
        pos_msg = YOLOMsg()
        
        # 오탐으로 인한 bbox 생성 시 오탐 방지
        annotated_frame = results[0].plot()
        # bbox가 생성된다면
        if len(results[0].boxes) > 0:
            self.fire_frame_cnt += 1
        else:
            self.fire_frame_cnt = 0
        
        # 비정상적인 값을 기본값으로 설정하여 초기화 (인식 X)
        pos_msg.x = -999.0
        pos_msg.y = -999.0
        
        if self.fire_frame_cnt >= 3:
            # 3프레임동안 bbox가 만들어지면
            if self.fire_frame_cnt % 3 == 0:
                # 터미널에 3프레임마다 'fire detect!' 출력
                self.get_logger().info('fire detect!')
                
            # bbox가 여러 개일 때, conf가 가장 높은 box가 최종 bbox로 선정
            best_conf = results[0].boxes.conf.argmax()           
            bounding_box = results[0].boxes.xywh[best_conf].tolist()

            # 설정한 카메라 픽셀에 맞게 카메라 중심의 x,y가 0이 되도록 조정
            pixel_x = float(bounding_box[0]) # X픽셀 (0 ~ 320)
            pixel_y = float(bounding_box[1]) # Y픽셀 (0 ~ 320)
            
            pos_msg.x = float(pixel_x - 160.0)  # -160 ~ 160
            pos_msg.y = float(pixel_y - 160.0)  # -160 ~ 160
            
            self.pos_pub.publish(pos_msg)
                
        else: # 불이 인식되지 않으면 기본값 전송
            self.pos_pub.publish(pos_msg)
                
        # PC에 TB3 카메라 뷰 연결
        # YOLO 모델이 적용한 cv2를 image 형태로 변환하고 PC에 출력
        msg = self.bridge.cv2_to_imgmsg(annotated_frame, encoding='bgr8')
        self.image_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = FireDetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
