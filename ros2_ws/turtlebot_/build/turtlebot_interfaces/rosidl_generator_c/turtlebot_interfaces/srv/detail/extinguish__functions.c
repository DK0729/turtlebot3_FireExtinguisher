// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlebot_interfaces:srv/Extinguish.idl
// generated code does not contain a copyright notice
#include "turtlebot_interfaces/srv/detail/extinguish__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
turtlebot_interfaces__srv__Extinguish_Request__init(turtlebot_interfaces__srv__Extinguish_Request * msg)
{
  if (!msg) {
    return false;
  }
  // y_val
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Request__fini(turtlebot_interfaces__srv__Extinguish_Request * msg)
{
  if (!msg) {
    return;
  }
  // y_val
}

bool
turtlebot_interfaces__srv__Extinguish_Request__are_equal(const turtlebot_interfaces__srv__Extinguish_Request * lhs, const turtlebot_interfaces__srv__Extinguish_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // y_val
  if (lhs->y_val != rhs->y_val) {
    return false;
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Request__copy(
  const turtlebot_interfaces__srv__Extinguish_Request * input,
  turtlebot_interfaces__srv__Extinguish_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // y_val
  output->y_val = input->y_val;
  return true;
}

turtlebot_interfaces__srv__Extinguish_Request *
turtlebot_interfaces__srv__Extinguish_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Request * msg = (turtlebot_interfaces__srv__Extinguish_Request *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot_interfaces__srv__Extinguish_Request));
  bool success = turtlebot_interfaces__srv__Extinguish_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot_interfaces__srv__Extinguish_Request__destroy(turtlebot_interfaces__srv__Extinguish_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot_interfaces__srv__Extinguish_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot_interfaces__srv__Extinguish_Request__Sequence__init(turtlebot_interfaces__srv__Extinguish_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Request * data = NULL;

  if (size) {
    data = (turtlebot_interfaces__srv__Extinguish_Request *)allocator.zero_allocate(size, sizeof(turtlebot_interfaces__srv__Extinguish_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot_interfaces__srv__Extinguish_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot_interfaces__srv__Extinguish_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Request__Sequence__fini(turtlebot_interfaces__srv__Extinguish_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlebot_interfaces__srv__Extinguish_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlebot_interfaces__srv__Extinguish_Request__Sequence *
turtlebot_interfaces__srv__Extinguish_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Request__Sequence * array = (turtlebot_interfaces__srv__Extinguish_Request__Sequence *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot_interfaces__srv__Extinguish_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot_interfaces__srv__Extinguish_Request__Sequence__destroy(turtlebot_interfaces__srv__Extinguish_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot_interfaces__srv__Extinguish_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot_interfaces__srv__Extinguish_Request__Sequence__are_equal(const turtlebot_interfaces__srv__Extinguish_Request__Sequence * lhs, const turtlebot_interfaces__srv__Extinguish_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Request__Sequence__copy(
  const turtlebot_interfaces__srv__Extinguish_Request__Sequence * input,
  turtlebot_interfaces__srv__Extinguish_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot_interfaces__srv__Extinguish_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot_interfaces__srv__Extinguish_Request * data =
      (turtlebot_interfaces__srv__Extinguish_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot_interfaces__srv__Extinguish_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot_interfaces__srv__Extinguish_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
turtlebot_interfaces__srv__Extinguish_Response__init(turtlebot_interfaces__srv__Extinguish_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Response__fini(turtlebot_interfaces__srv__Extinguish_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
turtlebot_interfaces__srv__Extinguish_Response__are_equal(const turtlebot_interfaces__srv__Extinguish_Response * lhs, const turtlebot_interfaces__srv__Extinguish_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Response__copy(
  const turtlebot_interfaces__srv__Extinguish_Response * input,
  turtlebot_interfaces__srv__Extinguish_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

turtlebot_interfaces__srv__Extinguish_Response *
turtlebot_interfaces__srv__Extinguish_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Response * msg = (turtlebot_interfaces__srv__Extinguish_Response *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot_interfaces__srv__Extinguish_Response));
  bool success = turtlebot_interfaces__srv__Extinguish_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot_interfaces__srv__Extinguish_Response__destroy(turtlebot_interfaces__srv__Extinguish_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot_interfaces__srv__Extinguish_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot_interfaces__srv__Extinguish_Response__Sequence__init(turtlebot_interfaces__srv__Extinguish_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Response * data = NULL;

  if (size) {
    data = (turtlebot_interfaces__srv__Extinguish_Response *)allocator.zero_allocate(size, sizeof(turtlebot_interfaces__srv__Extinguish_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot_interfaces__srv__Extinguish_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot_interfaces__srv__Extinguish_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Response__Sequence__fini(turtlebot_interfaces__srv__Extinguish_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlebot_interfaces__srv__Extinguish_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlebot_interfaces__srv__Extinguish_Response__Sequence *
turtlebot_interfaces__srv__Extinguish_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Response__Sequence * array = (turtlebot_interfaces__srv__Extinguish_Response__Sequence *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot_interfaces__srv__Extinguish_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot_interfaces__srv__Extinguish_Response__Sequence__destroy(turtlebot_interfaces__srv__Extinguish_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot_interfaces__srv__Extinguish_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot_interfaces__srv__Extinguish_Response__Sequence__are_equal(const turtlebot_interfaces__srv__Extinguish_Response__Sequence * lhs, const turtlebot_interfaces__srv__Extinguish_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Response__Sequence__copy(
  const turtlebot_interfaces__srv__Extinguish_Response__Sequence * input,
  turtlebot_interfaces__srv__Extinguish_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot_interfaces__srv__Extinguish_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot_interfaces__srv__Extinguish_Response * data =
      (turtlebot_interfaces__srv__Extinguish_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot_interfaces__srv__Extinguish_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot_interfaces__srv__Extinguish_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlebot_interfaces/srv/detail/extinguish__functions.h"

bool
turtlebot_interfaces__srv__Extinguish_Event__init(turtlebot_interfaces__srv__Extinguish_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    turtlebot_interfaces__srv__Extinguish_Event__fini(msg);
    return false;
  }
  // request
  if (!turtlebot_interfaces__srv__Extinguish_Request__Sequence__init(&msg->request, 0)) {
    turtlebot_interfaces__srv__Extinguish_Event__fini(msg);
    return false;
  }
  // response
  if (!turtlebot_interfaces__srv__Extinguish_Response__Sequence__init(&msg->response, 0)) {
    turtlebot_interfaces__srv__Extinguish_Event__fini(msg);
    return false;
  }
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Event__fini(turtlebot_interfaces__srv__Extinguish_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  turtlebot_interfaces__srv__Extinguish_Request__Sequence__fini(&msg->request);
  // response
  turtlebot_interfaces__srv__Extinguish_Response__Sequence__fini(&msg->response);
}

bool
turtlebot_interfaces__srv__Extinguish_Event__are_equal(const turtlebot_interfaces__srv__Extinguish_Event * lhs, const turtlebot_interfaces__srv__Extinguish_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!turtlebot_interfaces__srv__Extinguish_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!turtlebot_interfaces__srv__Extinguish_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Event__copy(
  const turtlebot_interfaces__srv__Extinguish_Event * input,
  turtlebot_interfaces__srv__Extinguish_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!turtlebot_interfaces__srv__Extinguish_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!turtlebot_interfaces__srv__Extinguish_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

turtlebot_interfaces__srv__Extinguish_Event *
turtlebot_interfaces__srv__Extinguish_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Event * msg = (turtlebot_interfaces__srv__Extinguish_Event *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot_interfaces__srv__Extinguish_Event));
  bool success = turtlebot_interfaces__srv__Extinguish_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot_interfaces__srv__Extinguish_Event__destroy(turtlebot_interfaces__srv__Extinguish_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot_interfaces__srv__Extinguish_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot_interfaces__srv__Extinguish_Event__Sequence__init(turtlebot_interfaces__srv__Extinguish_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Event * data = NULL;

  if (size) {
    data = (turtlebot_interfaces__srv__Extinguish_Event *)allocator.zero_allocate(size, sizeof(turtlebot_interfaces__srv__Extinguish_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot_interfaces__srv__Extinguish_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot_interfaces__srv__Extinguish_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlebot_interfaces__srv__Extinguish_Event__Sequence__fini(turtlebot_interfaces__srv__Extinguish_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlebot_interfaces__srv__Extinguish_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlebot_interfaces__srv__Extinguish_Event__Sequence *
turtlebot_interfaces__srv__Extinguish_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__srv__Extinguish_Event__Sequence * array = (turtlebot_interfaces__srv__Extinguish_Event__Sequence *)allocator.allocate(sizeof(turtlebot_interfaces__srv__Extinguish_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot_interfaces__srv__Extinguish_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot_interfaces__srv__Extinguish_Event__Sequence__destroy(turtlebot_interfaces__srv__Extinguish_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot_interfaces__srv__Extinguish_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot_interfaces__srv__Extinguish_Event__Sequence__are_equal(const turtlebot_interfaces__srv__Extinguish_Event__Sequence * lhs, const turtlebot_interfaces__srv__Extinguish_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot_interfaces__srv__Extinguish_Event__Sequence__copy(
  const turtlebot_interfaces__srv__Extinguish_Event__Sequence * input,
  turtlebot_interfaces__srv__Extinguish_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot_interfaces__srv__Extinguish_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot_interfaces__srv__Extinguish_Event * data =
      (turtlebot_interfaces__srv__Extinguish_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot_interfaces__srv__Extinguish_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot_interfaces__srv__Extinguish_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot_interfaces__srv__Extinguish_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
