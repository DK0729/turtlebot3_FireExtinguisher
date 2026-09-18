// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlebot_interfaces:srv/Extinguish.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlebot_interfaces/srv/extinguish.hpp"


#ifndef TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__BUILDER_HPP_
#define TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlebot_interfaces/srv/detail/extinguish__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlebot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Extinguish_Request_y_val
{
public:
  Init_Extinguish_Request_y_val()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlebot_interfaces::srv::Extinguish_Request y_val(::turtlebot_interfaces::srv::Extinguish_Request::_y_val_type arg)
  {
    msg_.y_val = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot_interfaces::srv::Extinguish_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot_interfaces::srv::Extinguish_Request>()
{
  return turtlebot_interfaces::srv::builder::Init_Extinguish_Request_y_val();
}

}  // namespace turtlebot_interfaces


namespace turtlebot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Extinguish_Response_success
{
public:
  Init_Extinguish_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlebot_interfaces::srv::Extinguish_Response success(::turtlebot_interfaces::srv::Extinguish_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot_interfaces::srv::Extinguish_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot_interfaces::srv::Extinguish_Response>()
{
  return turtlebot_interfaces::srv::builder::Init_Extinguish_Response_success();
}

}  // namespace turtlebot_interfaces


namespace turtlebot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Extinguish_Event_response
{
public:
  explicit Init_Extinguish_Event_response(::turtlebot_interfaces::srv::Extinguish_Event & msg)
  : msg_(msg)
  {}
  ::turtlebot_interfaces::srv::Extinguish_Event response(::turtlebot_interfaces::srv::Extinguish_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlebot_interfaces::srv::Extinguish_Event msg_;
};

class Init_Extinguish_Event_request
{
public:
  explicit Init_Extinguish_Event_request(::turtlebot_interfaces::srv::Extinguish_Event & msg)
  : msg_(msg)
  {}
  Init_Extinguish_Event_response request(::turtlebot_interfaces::srv::Extinguish_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Extinguish_Event_response(msg_);
  }

private:
  ::turtlebot_interfaces::srv::Extinguish_Event msg_;
};

class Init_Extinguish_Event_info
{
public:
  Init_Extinguish_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Extinguish_Event_request info(::turtlebot_interfaces::srv::Extinguish_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Extinguish_Event_request(msg_);
  }

private:
  ::turtlebot_interfaces::srv::Extinguish_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlebot_interfaces::srv::Extinguish_Event>()
{
  return turtlebot_interfaces::srv::builder::Init_Extinguish_Event_info();
}

}  // namespace turtlebot_interfaces

#endif  // TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__BUILDER_HPP_
