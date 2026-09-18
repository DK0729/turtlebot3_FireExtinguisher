// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlebot_interfaces:msg/Yolo.idl
// generated code does not contain a copyright notice
#include "turtlebot_interfaces/msg/detail/yolo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtlebot_interfaces__msg__Yolo__init(turtlebot_interfaces__msg__Yolo * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
turtlebot_interfaces__msg__Yolo__fini(turtlebot_interfaces__msg__Yolo * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
turtlebot_interfaces__msg__Yolo__are_equal(const turtlebot_interfaces__msg__Yolo * lhs, const turtlebot_interfaces__msg__Yolo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
turtlebot_interfaces__msg__Yolo__copy(
  const turtlebot_interfaces__msg__Yolo * input,
  turtlebot_interfaces__msg__Yolo * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

turtlebot_interfaces__msg__Yolo *
turtlebot_interfaces__msg__Yolo__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__msg__Yolo * msg = (turtlebot_interfaces__msg__Yolo *)allocator.allocate(sizeof(turtlebot_interfaces__msg__Yolo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlebot_interfaces__msg__Yolo));
  bool success = turtlebot_interfaces__msg__Yolo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlebot_interfaces__msg__Yolo__destroy(turtlebot_interfaces__msg__Yolo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlebot_interfaces__msg__Yolo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlebot_interfaces__msg__Yolo__Sequence__init(turtlebot_interfaces__msg__Yolo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__msg__Yolo * data = NULL;

  if (size) {
    data = (turtlebot_interfaces__msg__Yolo *)allocator.zero_allocate(size, sizeof(turtlebot_interfaces__msg__Yolo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlebot_interfaces__msg__Yolo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlebot_interfaces__msg__Yolo__fini(&data[i - 1]);
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
turtlebot_interfaces__msg__Yolo__Sequence__fini(turtlebot_interfaces__msg__Yolo__Sequence * array)
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
      turtlebot_interfaces__msg__Yolo__fini(&array->data[i]);
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

turtlebot_interfaces__msg__Yolo__Sequence *
turtlebot_interfaces__msg__Yolo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlebot_interfaces__msg__Yolo__Sequence * array = (turtlebot_interfaces__msg__Yolo__Sequence *)allocator.allocate(sizeof(turtlebot_interfaces__msg__Yolo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlebot_interfaces__msg__Yolo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlebot_interfaces__msg__Yolo__Sequence__destroy(turtlebot_interfaces__msg__Yolo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlebot_interfaces__msg__Yolo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlebot_interfaces__msg__Yolo__Sequence__are_equal(const turtlebot_interfaces__msg__Yolo__Sequence * lhs, const turtlebot_interfaces__msg__Yolo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlebot_interfaces__msg__Yolo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlebot_interfaces__msg__Yolo__Sequence__copy(
  const turtlebot_interfaces__msg__Yolo__Sequence * input,
  turtlebot_interfaces__msg__Yolo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlebot_interfaces__msg__Yolo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlebot_interfaces__msg__Yolo * data =
      (turtlebot_interfaces__msg__Yolo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlebot_interfaces__msg__Yolo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlebot_interfaces__msg__Yolo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlebot_interfaces__msg__Yolo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
