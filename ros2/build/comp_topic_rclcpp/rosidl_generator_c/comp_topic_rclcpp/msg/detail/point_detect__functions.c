// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_topic_rclcpp:msg/PointDetect.idl
// generated code does not contain a copyright notice
#include "comp_topic_rclcpp/msg/detail/point_detect__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
comp_topic_rclcpp__msg__PointDetect__init(comp_topic_rclcpp__msg__PointDetect * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
comp_topic_rclcpp__msg__PointDetect__fini(comp_topic_rclcpp__msg__PointDetect * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
comp_topic_rclcpp__msg__PointDetect__are_equal(const comp_topic_rclcpp__msg__PointDetect * lhs, const comp_topic_rclcpp__msg__PointDetect * rhs)
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
comp_topic_rclcpp__msg__PointDetect__copy(
  const comp_topic_rclcpp__msg__PointDetect * input,
  comp_topic_rclcpp__msg__PointDetect * output)
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

comp_topic_rclcpp__msg__PointDetect *
comp_topic_rclcpp__msg__PointDetect__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__PointDetect * msg = (comp_topic_rclcpp__msg__PointDetect *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__PointDetect), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_topic_rclcpp__msg__PointDetect));
  bool success = comp_topic_rclcpp__msg__PointDetect__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_topic_rclcpp__msg__PointDetect__destroy(comp_topic_rclcpp__msg__PointDetect * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_topic_rclcpp__msg__PointDetect__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_topic_rclcpp__msg__PointDetect__Sequence__init(comp_topic_rclcpp__msg__PointDetect__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__PointDetect * data = NULL;

  if (size) {
    data = (comp_topic_rclcpp__msg__PointDetect *)allocator.zero_allocate(size, sizeof(comp_topic_rclcpp__msg__PointDetect), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_topic_rclcpp__msg__PointDetect__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_topic_rclcpp__msg__PointDetect__fini(&data[i - 1]);
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
comp_topic_rclcpp__msg__PointDetect__Sequence__fini(comp_topic_rclcpp__msg__PointDetect__Sequence * array)
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
      comp_topic_rclcpp__msg__PointDetect__fini(&array->data[i]);
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

comp_topic_rclcpp__msg__PointDetect__Sequence *
comp_topic_rclcpp__msg__PointDetect__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__PointDetect__Sequence * array = (comp_topic_rclcpp__msg__PointDetect__Sequence *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__PointDetect__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_topic_rclcpp__msg__PointDetect__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_topic_rclcpp__msg__PointDetect__Sequence__destroy(comp_topic_rclcpp__msg__PointDetect__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_topic_rclcpp__msg__PointDetect__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_topic_rclcpp__msg__PointDetect__Sequence__are_equal(const comp_topic_rclcpp__msg__PointDetect__Sequence * lhs, const comp_topic_rclcpp__msg__PointDetect__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_topic_rclcpp__msg__PointDetect__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_topic_rclcpp__msg__PointDetect__Sequence__copy(
  const comp_topic_rclcpp__msg__PointDetect__Sequence * input,
  comp_topic_rclcpp__msg__PointDetect__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_topic_rclcpp__msg__PointDetect);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_topic_rclcpp__msg__PointDetect * data =
      (comp_topic_rclcpp__msg__PointDetect *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_topic_rclcpp__msg__PointDetect__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_topic_rclcpp__msg__PointDetect__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_topic_rclcpp__msg__PointDetect__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
