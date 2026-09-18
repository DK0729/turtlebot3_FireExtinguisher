import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction
from launch_ros.actions import Node

def generate_launch_description():
    
    # RViz 설정 파일 경로 미리 정의 (가독성을 위해 분리)
    rviz_config_path = os.path.join(
        get_package_share_directory('turtlebot3_navigation2'),
        'rviz',
        'tb3_navigation2.rviz'
    )

    # ==========================================
    # 🔇 1. 화면에 로그를 띄우지 않을 노드들 (조용히 실행)
    # ==========================================
    
    fire_detector_node = Node(
        package='fire_detect',
        executable='fire_detector',
        name='fire_detector',
        output='log'
    )

    rqt_image_view_node = Node(
        package='rqt_image_view',
        executable='rqt_image_view',
        name='rqt_image_view',
        output='log'
    )

    # 💡 [수정됨] RViz2 노드: Node 대신 ExecuteProcess를 사용하여 완벽 차단
    # --ros-args --log-level FATAL 을 추가하여 치명적 오류가 아니면 ROS 내부적으로도 무시하게 만들고,
    # > /dev/null 2>&1 을 통해 bash 터미널/파일 출력도 물리적으로 폐기합니다.
    rviz_node = ExecuteProcess(
        cmd=['bash', '-c', f'ros2 run rviz2 rviz2 -d {rviz_config_path} --ros-args --log-level FATAL > /dev/null 2>&1'],
        output='log'
    )

    cartographer_launch = ExecuteProcess(
        cmd=['bash', '-c', 'ros2 launch turtlebot3_cartographer cartographer.launch.py > /dev/null 2>&1'],
        output='log'
    )

    nav2_launch = ExecuteProcess(
        cmd=['bash', '-c', 'ros2 launch nav2_bringup navigation_launch.py use_sim_time:=False params_file:=/home/donggwan/turtlebot3_ws/src/turtlebot3/turtlebot3_navigation2/param/burger.yaml > /dev/null 2>&1'],
        output='log'
    )

    # ==========================================
    # 🔊 2. 터미널에서 로그를 볼 노드들 (집중 모니터링)
    # ==========================================
    
    frontier_explorer_node = Node(
        package='frontier_exploration_ros2',
        executable='frontier_explorer',
        name='frontier_explorer',
        parameters=[{'autostart': False}],
        output='screen'
    )

    exploration_node = Node(
        package='turtlebot_control_node',
        executable='exploration_node',
        name='exploration_node',
        output='screen'
    )

    # LaunchDescription 반환
    return LaunchDescription([
        fire_detector_node,
        rqt_image_view_node,
        cartographer_launch,
        nav2_launch,
        rviz_node,
        frontier_explorer_node,
        exploration_node
    ])
