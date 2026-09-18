// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtlebot_interfaces:srv/Extinguish.idl
// generated code does not contain a copyright notice

#include "turtlebot_interfaces/srv/detail/extinguish__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtlebot_interfaces
const rosidl_type_hash_t *
turtlebot_interfaces__srv__Extinguish__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0xa1, 0x59, 0x03, 0x15, 0x77, 0xc4, 0x23,
      0xa0, 0xc4, 0x3b, 0xcc, 0x1e, 0xbc, 0x1d, 0x8d,
      0x9e, 0x84, 0x3f, 0x67, 0x12, 0xb3, 0x30, 0xe5,
      0x0e, 0x7f, 0x17, 0x74, 0xac, 0x15, 0xf2, 0xc4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlebot_interfaces
const rosidl_type_hash_t *
turtlebot_interfaces__srv__Extinguish_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf9, 0x7b, 0x81, 0xb2, 0x16, 0xa0, 0xa1, 0xd6,
      0xcd, 0x8c, 0xf9, 0x60, 0x56, 0xf0, 0x7e, 0x74,
      0x88, 0x55, 0x9d, 0x8f, 0x67, 0xe7, 0x79, 0x39,
      0xa5, 0x78, 0x6b, 0x54, 0x75, 0x65, 0x03, 0x44,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlebot_interfaces
const rosidl_type_hash_t *
turtlebot_interfaces__srv__Extinguish_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x41, 0xd2, 0x52, 0xc5, 0xb0, 0x51, 0x51, 0x53,
      0x91, 0x54, 0x4a, 0xc6, 0x34, 0x8b, 0xc6, 0x1b,
      0xbb, 0x9e, 0x19, 0xe3, 0x34, 0x23, 0x57, 0xe7,
      0x58, 0x17, 0xf9, 0xf5, 0x6b, 0xa3, 0xce, 0xbb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_turtlebot_interfaces
const rosidl_type_hash_t *
turtlebot_interfaces__srv__Extinguish_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0x7c, 0x71, 0x1a, 0x6e, 0xd6, 0x4d, 0xcf,
      0x66, 0x01, 0x2a, 0xa3, 0xc0, 0xe6, 0xdf, 0xba,
      0x54, 0x03, 0xd0, 0xe7, 0xab, 0x04, 0xe6, 0x99,
      0x92, 0xf6, 0x01, 0xde, 0xa8, 0x52, 0x1d, 0xfb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char turtlebot_interfaces__srv__Extinguish__TYPE_NAME[] = "turtlebot_interfaces/srv/Extinguish";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char turtlebot_interfaces__srv__Extinguish_Event__TYPE_NAME[] = "turtlebot_interfaces/srv/Extinguish_Event";
static char turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME[] = "turtlebot_interfaces/srv/Extinguish_Request";
static char turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME[] = "turtlebot_interfaces/srv/Extinguish_Response";

// Define type names, field names, and default values
static char turtlebot_interfaces__srv__Extinguish__FIELD_NAME__request_message[] = "request_message";
static char turtlebot_interfaces__srv__Extinguish__FIELD_NAME__response_message[] = "response_message";
static char turtlebot_interfaces__srv__Extinguish__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field turtlebot_interfaces__srv__Extinguish__FIELDS[] = {
  {
    {turtlebot_interfaces__srv__Extinguish__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {turtlebot_interfaces__srv__Extinguish_Event__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtlebot_interfaces__srv__Extinguish__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Event__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlebot_interfaces__srv__Extinguish__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlebot_interfaces__srv__Extinguish__TYPE_NAME, 35, 35},
      {turtlebot_interfaces__srv__Extinguish__FIELDS, 3, 3},
    },
    {turtlebot_interfaces__srv__Extinguish__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = turtlebot_interfaces__srv__Extinguish_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = turtlebot_interfaces__srv__Extinguish_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = turtlebot_interfaces__srv__Extinguish_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlebot_interfaces__srv__Extinguish_Request__FIELD_NAME__y_val[] = "y_val";

static rosidl_runtime_c__type_description__Field turtlebot_interfaces__srv__Extinguish_Request__FIELDS[] = {
  {
    {turtlebot_interfaces__srv__Extinguish_Request__FIELD_NAME__y_val, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlebot_interfaces__srv__Extinguish_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
      {turtlebot_interfaces__srv__Extinguish_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlebot_interfaces__srv__Extinguish_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field turtlebot_interfaces__srv__Extinguish_Response__FIELDS[] = {
  {
    {turtlebot_interfaces__srv__Extinguish_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlebot_interfaces__srv__Extinguish_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
      {turtlebot_interfaces__srv__Extinguish_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__info[] = "info";
static char turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__request[] = "request";
static char turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field turtlebot_interfaces__srv__Extinguish_Event__FIELDS[] = {
  {
    {turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtlebot_interfaces__srv__Extinguish_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtlebot_interfaces__srv__Extinguish_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtlebot_interfaces__srv__Extinguish_Event__TYPE_NAME, 41, 41},
      {turtlebot_interfaces__srv__Extinguish_Event__FIELDS, 3, 3},
    },
    {turtlebot_interfaces__srv__Extinguish_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = turtlebot_interfaces__srv__Extinguish_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = turtlebot_interfaces__srv__Extinguish_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request (PC -> Arduino)\n"
  "float32 y_val \n"
  "---\n"
  "# Response (Arduino -> PC)\n"
  "int32 success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtlebot_interfaces__srv__Extinguish__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlebot_interfaces__srv__Extinguish__TYPE_NAME, 35, 35},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 86, 86},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlebot_interfaces__srv__Extinguish_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlebot_interfaces__srv__Extinguish_Request__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlebot_interfaces__srv__Extinguish_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlebot_interfaces__srv__Extinguish_Response__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
turtlebot_interfaces__srv__Extinguish_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtlebot_interfaces__srv__Extinguish_Event__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlebot_interfaces__srv__Extinguish__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlebot_interfaces__srv__Extinguish__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *turtlebot_interfaces__srv__Extinguish_Event__get_individual_type_description_source(NULL);
    sources[4] = *turtlebot_interfaces__srv__Extinguish_Request__get_individual_type_description_source(NULL);
    sources[5] = *turtlebot_interfaces__srv__Extinguish_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlebot_interfaces__srv__Extinguish_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlebot_interfaces__srv__Extinguish_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlebot_interfaces__srv__Extinguish_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlebot_interfaces__srv__Extinguish_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtlebot_interfaces__srv__Extinguish_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtlebot_interfaces__srv__Extinguish_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *turtlebot_interfaces__srv__Extinguish_Request__get_individual_type_description_source(NULL);
    sources[4] = *turtlebot_interfaces__srv__Extinguish_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
