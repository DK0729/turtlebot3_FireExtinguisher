// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlebot_interfaces/msg/detail/yolo__functions.h"
#include "turtlebot_interfaces/msg/detail/yolo__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace turtlebot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Yolo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) turtlebot_interfaces::msg::Yolo(_init);
}

void Yolo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<turtlebot_interfaces::msg::Yolo *>(message_memory);
  typed_message->~Yolo();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Yolo_message_member_array[2] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot_interfaces::msg::Yolo, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot_interfaces::msg::Yolo, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Yolo_message_members = {
  "turtlebot_interfaces::msg",  // message namespace
  "Yolo",  // message name
  2,  // number of fields
  sizeof(turtlebot_interfaces::msg::Yolo),
  false,  // has_any_key_member_
  Yolo_message_member_array,  // message members
  Yolo_init_function,  // function to initialize message memory (memory has to be allocated)
  Yolo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Yolo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Yolo_message_members,
  get_message_typesupport_handle_function,
  &turtlebot_interfaces__msg__Yolo__get_type_hash,
  &turtlebot_interfaces__msg__Yolo__get_type_description,
  &turtlebot_interfaces__msg__Yolo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace turtlebot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<turtlebot_interfaces::msg::Yolo>()
{
  return &::turtlebot_interfaces::msg::rosidl_typesupport_introspection_cpp::Yolo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, turtlebot_interfaces, msg, Yolo)() {
  return &::turtlebot_interfaces::msg::rosidl_typesupport_introspection_cpp::Yolo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
