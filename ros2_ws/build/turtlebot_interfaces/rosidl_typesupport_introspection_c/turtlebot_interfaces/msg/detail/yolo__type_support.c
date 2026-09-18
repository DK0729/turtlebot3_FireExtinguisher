// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlebot_interfaces/msg/detail/yolo__rosidl_typesupport_introspection_c.h"
#include "turtlebot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlebot_interfaces/msg/detail/yolo__functions.h"
#include "turtlebot_interfaces/msg/detail/yolo__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlebot_interfaces__msg__Yolo__init(message_memory);
}

void turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_fini_function(void * message_memory)
{
  turtlebot_interfaces__msg__Yolo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot_interfaces__msg__Yolo, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlebot_interfaces__msg__Yolo, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_members = {
  "turtlebot_interfaces__msg",  // message namespace
  "Yolo",  // message name
  2,  // number of fields
  sizeof(turtlebot_interfaces__msg__Yolo),
  false,  // has_any_key_member_
  turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_member_array,  // message members
  turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_type_support_handle = {
  0,
  &turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_members,
  get_message_typesupport_handle_function,
  &turtlebot_interfaces__msg__Yolo__get_type_hash,
  &turtlebot_interfaces__msg__Yolo__get_type_description,
  &turtlebot_interfaces__msg__Yolo__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlebot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlebot_interfaces, msg, Yolo)() {
  if (!turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_type_support_handle.typesupport_identifier) {
    turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlebot_interfaces__msg__Yolo__rosidl_typesupport_introspection_c__Yolo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
