// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlebot_interfaces:srv/Extinguish.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlebot_interfaces/srv/extinguish.h"


#ifndef TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__STRUCT_H_
#define TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Extinguish in the package turtlebot_interfaces.
typedef struct turtlebot_interfaces__srv__Extinguish_Request
{
  float y_val;
} turtlebot_interfaces__srv__Extinguish_Request;

// Struct for a sequence of turtlebot_interfaces__srv__Extinguish_Request.
typedef struct turtlebot_interfaces__srv__Extinguish_Request__Sequence
{
  turtlebot_interfaces__srv__Extinguish_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot_interfaces__srv__Extinguish_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Extinguish in the package turtlebot_interfaces.
typedef struct turtlebot_interfaces__srv__Extinguish_Response
{
  int32_t success;
} turtlebot_interfaces__srv__Extinguish_Response;

// Struct for a sequence of turtlebot_interfaces__srv__Extinguish_Response.
typedef struct turtlebot_interfaces__srv__Extinguish_Response__Sequence
{
  turtlebot_interfaces__srv__Extinguish_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot_interfaces__srv__Extinguish_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  turtlebot_interfaces__srv__Extinguish_Event__request__MAX_SIZE = 1
};
// response
enum
{
  turtlebot_interfaces__srv__Extinguish_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Extinguish in the package turtlebot_interfaces.
typedef struct turtlebot_interfaces__srv__Extinguish_Event
{
  service_msgs__msg__ServiceEventInfo info;
  turtlebot_interfaces__srv__Extinguish_Request__Sequence request;
  turtlebot_interfaces__srv__Extinguish_Response__Sequence response;
} turtlebot_interfaces__srv__Extinguish_Event;

// Struct for a sequence of turtlebot_interfaces__srv__Extinguish_Event.
typedef struct turtlebot_interfaces__srv__Extinguish_Event__Sequence
{
  turtlebot_interfaces__srv__Extinguish_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlebot_interfaces__srv__Extinguish_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT_INTERFACES__SRV__DETAIL__EXTINGUISH__STRUCT_H_
