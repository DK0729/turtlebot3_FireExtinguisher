// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlebot_interfaces/msg/yolo.h"


#ifndef TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__STRUCT_H_
#define TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Yolo in the package turtlebot_interfaces.
typedef struct turtlebot_interfaces__msg__Yolo
{
  double x;
  double y;
} turtlebot_interfaces__msg__Yolo;

// Struct for a sequence of turtlebot_interfaces__msg__Yolo.
typedef struct turtlebot_interfaces__msg__Yolo__Sequence
{
  turtlebot_interfaces__msg__Yolo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot_interfaces__msg__Yolo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT_INTERFACES__MSG__DETAIL__YOLO__STRUCT_H_
