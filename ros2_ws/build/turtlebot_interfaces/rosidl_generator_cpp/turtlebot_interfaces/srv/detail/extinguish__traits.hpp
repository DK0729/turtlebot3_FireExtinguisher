// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlebot_interfaces:srv/Extinguish.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlebot_interfaces/srv/extinguish.hpp"


#ifndef TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__TRAITS_HPP_
#define TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlebot_interfaces/srv/detail/extinguish__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlebot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Extinguish_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: y_val
  {
    out << "y_val: ";
    rosidl_generator_traits::value_to_yaml(msg.y_val, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Extinguish_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: y_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_val: ";
    rosidl_generator_traits::value_to_yaml(msg.y_val, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Extinguish_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtlebot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtlebot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlebot_interfaces::srv::Extinguish_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlebot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlebot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtlebot_interfaces::srv::Extinguish_Request & msg)
{
  return turtlebot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtlebot_interfaces::srv::Extinguish_Request>()
{
  return "turtlebot_interfaces::srv::Extinguish_Request";
}

template<>
inline const char * name<turtlebot_interfaces::srv::Extinguish_Request>()
{
  return "turtlebot_interfaces/srv/Extinguish_Request";
}

template<>
struct has_fixed_size<turtlebot_interfaces::srv::Extinguish_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlebot_interfaces::srv::Extinguish_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlebot_interfaces::srv::Extinguish_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtlebot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Extinguish_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Extinguish_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Extinguish_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtlebot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtlebot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlebot_interfaces::srv::Extinguish_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlebot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlebot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtlebot_interfaces::srv::Extinguish_Response & msg)
{
  return turtlebot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtlebot_interfaces::srv::Extinguish_Response>()
{
  return "turtlebot_interfaces::srv::Extinguish_Response";
}

template<>
inline const char * name<turtlebot_interfaces::srv::Extinguish_Response>()
{
  return "turtlebot_interfaces/srv/Extinguish_Response";
}

template<>
struct has_fixed_size<turtlebot_interfaces::srv::Extinguish_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlebot_interfaces::srv::Extinguish_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlebot_interfaces::srv::Extinguish_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace turtlebot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Extinguish_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Extinguish_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Extinguish_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtlebot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtlebot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlebot_interfaces::srv::Extinguish_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlebot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlebot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtlebot_interfaces::srv::Extinguish_Event & msg)
{
  return turtlebot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtlebot_interfaces::srv::Extinguish_Event>()
{
  return "turtlebot_interfaces::srv::Extinguish_Event";
}

template<>
inline const char * name<turtlebot_interfaces::srv::Extinguish_Event>()
{
  return "turtlebot_interfaces/srv/Extinguish_Event";
}

template<>
struct has_fixed_size<turtlebot_interfaces::srv::Extinguish_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlebot_interfaces::srv::Extinguish_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtlebot_interfaces::srv::Extinguish_Request>::value && has_bounded_size<turtlebot_interfaces::srv::Extinguish_Response>::value> {};

template<>
struct is_message<turtlebot_interfaces::srv::Extinguish_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtlebot_interfaces::srv::Extinguish>()
{
  return "turtlebot_interfaces::srv::Extinguish";
}

template<>
inline const char * name<turtlebot_interfaces::srv::Extinguish>()
{
  return "turtlebot_interfaces/srv/Extinguish";
}

template<>
struct has_fixed_size<turtlebot_interfaces::srv::Extinguish>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlebot_interfaces::srv::Extinguish_Request>::value &&
    has_fixed_size<turtlebot_interfaces::srv::Extinguish_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlebot_interfaces::srv::Extinguish>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlebot_interfaces::srv::Extinguish_Request>::value &&
    has_bounded_size<turtlebot_interfaces::srv::Extinguish_Response>::value
  >
{
};

template<>
struct is_service<turtlebot_interfaces::srv::Extinguish>
  : std::true_type
{
};

template<>
struct is_service_request<turtlebot_interfaces::srv::Extinguish_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlebot_interfaces::srv::Extinguish_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__TRAITS_HPP_
