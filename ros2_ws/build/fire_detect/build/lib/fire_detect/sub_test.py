import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point

class SubTest(Node):
    def __init__(self):
        super().__init__('sub_test')
        self.subscription = self.create_subscription(
            Point,
            '/yolo_detection',
            self.listener_callback,
            10
        )
        
    def listener_callback(self, msg):
       self.get_logger().info(f"Point : [{msg.x}, {msg.y}]")
       
def main(args=None):
    rclpy.init(args=args)
    node = SubTest()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main() 
