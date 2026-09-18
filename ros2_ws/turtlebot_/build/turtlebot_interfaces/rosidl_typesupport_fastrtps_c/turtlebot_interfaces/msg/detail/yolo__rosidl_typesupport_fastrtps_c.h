// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice
#ifndef TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlebot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "turtlebot_interfaces/msg/detail/yolo__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
bool cdr_serialize_turtlebot_interfaces__msg__Yolo(
  const turtlebot_interfaces__msg__Yolo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
bool cdr_deserialize_turtlebot_interfaces__msg__Yolo(
  eprosima::fastcdr::Cdr &,
  turtlebot_interfaces__msg__Yolo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
size_t get_serialized_size_turtlebot_interfaces__msg__Yolo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
size_t max_serialized_size_turtlebot_interfaces__msg__Yolo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
bool cdr_serialize_key_turtlebot_interfaces__msg__Yolo(
  const turtlebot_interfaces__msg__Yolo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
size_t get_serialized_size_key_turtlebot_interfaces__msg__Yolo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
size_t max_serialized_size_key_turtlebot_interfaces__msg__Yolo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlebot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtlebot_interfaces, msg, Yolo)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
