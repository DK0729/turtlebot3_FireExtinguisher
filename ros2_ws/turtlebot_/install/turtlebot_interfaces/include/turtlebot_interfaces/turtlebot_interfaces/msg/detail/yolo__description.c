// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice

#include "turtlebot_interfaces/msg/detail/yolo__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlebot_interfaces
const rosidl_type_hash_t *
turtlebot_interfaces__msg__Yolo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x22, 0xf1, 0x6d, 0x7c, 0x8a, 0x0c, 0x45, 0x06,
      0x79, 0x51, 0x07, 0x57, 0x07, 0x63, 0x19, 0x6b,
      0x2c, 0xeb, 0x79, 0xde, 0x19, 0xd9, 0x8b, 0x47,
      0x76, 0x2f, 0xc5, 0xbb, 0xa7, 0xc1, 0xaa, 0xaf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char turtlebot_interfaces__msg__Yolo__TYPE_NAME[] = "turtlebot_interfaces/msg/Yolo";

// Define type names, field names, and default values
static char turtlebot_interfaces__msg__Yolo__FIELD_NAME__x[] = "x";
static char turtlebot_interfaces__msg__Yolo__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field turtlebot_interfaces__msg__Yolo__FIELDS[] = {
  {
    {turtlebot_interfaces__msg__Yolo__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__msg__Yolo__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlebot_interfaces__msg__Yolo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlebot_interfaces__msg__Yolo__TYPE_NAME, 29, 29},
      {turtlebot_interfaces__msg__Yolo__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlebot_interfaces__msg__Yolo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlebot_interfaces__msg__Yolo__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 20, 20},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlebot_interfaces__msg__Yolo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlebot_interfaces__msg__Yolo__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
