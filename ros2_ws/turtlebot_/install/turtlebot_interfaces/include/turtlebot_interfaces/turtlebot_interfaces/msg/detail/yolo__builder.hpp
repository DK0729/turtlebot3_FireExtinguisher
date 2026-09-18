// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlebot_interfaces/msg/yolo.hpp"


#ifndef TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__BUILDER_HPP_
#define TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlebot_interfaces/msg/detail/yolo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlebot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Yolo_y
{
public:
  explicit Init_Yolo_y(::turtlebot_interfaces::msg::Yolo & msg)
  : msg_(msg)
  {}
  ::turtlebot_interfaces::msg::Yolo y(::turtlebot_interfaces::msg::Yolo::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot_interfaces::msg::Yolo msg_;
};

class Init_Yolo_x
{
public:
  Init_Yolo_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Yolo_y x(::turtlebot_interfaces::msg::Yolo::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Yolo_y(msg_);
  }

private:
  ::turtlebot_interfaces::msg::Yolo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot_interfaces::msg::Yolo>()
{
  return turtlebot_interfaces::msg::builder::Init_Yolo_x();
}

}  // namespace turtlebot_interfaces

#endif  // TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__BUILDER_HPP_
