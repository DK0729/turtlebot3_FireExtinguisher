cmake_minimum_required(VERSION 3.8)
project(turtlebot_control_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(turtlebot_interfaces REQUIRED)

find_package(visualization_msgs REQUIRED)
find_package(frontier_exploration_ros2 REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(exploration_node src/exploration_node.cpp)

ament_target_dependencies(exploration_node
  rclcpp
  rclcpp_action
  std_msgs
  geometry_msgs
  sensor_msgs
  nav_msgs
  turtlebot_interfaces
  visualization_msgs
  nav2_msgs
frontier_exploration_ros2
)

add_executable(arduino_node src/arduino_node.cpp)
ament_target_dependencies(arduino_node
  rclcpp
  turtlebot_interfaces
)

install(TARGETS
  exploration_node
  arduino_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
