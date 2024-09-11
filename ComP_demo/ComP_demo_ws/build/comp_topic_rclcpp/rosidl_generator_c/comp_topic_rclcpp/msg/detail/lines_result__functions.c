// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_topic_rclcpp:msg/LinesResult.idl
// generated code does not contain a copyright notice
#include "comp_topic_rclcpp/msg/detail/lane_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `left1`
// Member `right1`
// Member `left2`
// Member `right2`
#include "comp_topic_rclcpp/msg/detail/point_detect__functions.h"

bool
comp_topic_rclcpp__msg__LinesResult__init(comp_topic_rclcpp__msg__LinesResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
    return false;
  }
  // left1
  if (!comp_topic_rclcpp__msg__PointDetect__init(&msg->left1)) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
    return false;
  }
  // right1
  if (!comp_topic_rclcpp__msg__PointDetect__init(&msg->right1)) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
    return false;
  }
  // left2
  if (!comp_topic_rclcpp__msg__PointDetect__init(&msg->left2)) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
    return false;
  }
  // right2
  if (!comp_topic_rclcpp__msg__PointDetect__init(&msg->right2)) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
    return false;
  }
  return true;
}

void
comp_topic_rclcpp__msg__LinesResult__fini(comp_topic_rclcpp__msg__LinesResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // left1
  comp_topic_rclcpp__msg__PointDetect__fini(&msg->left1);
  // right1
  comp_topic_rclcpp__msg__PointDetect__fini(&msg->right1);
  // left2
  comp_topic_rclcpp__msg__PointDetect__fini(&msg->left2);
  // right2
  comp_topic_rclcpp__msg__PointDetect__fini(&msg->right2);
}

bool
comp_topic_rclcpp__msg__LinesResult__are_equal(const comp_topic_rclcpp__msg__LinesResult * lhs, const comp_topic_rclcpp__msg__LinesResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // left1
  if (!comp_topic_rclcpp__msg__PointDetect__are_equal(
      &(lhs->left1), &(rhs->left1)))
  {
    return false;
  }
  // right1
  if (!comp_topic_rclcpp__msg__PointDetect__are_equal(
      &(lhs->right1), &(rhs->right1)))
  {
    return false;
  }
  // left2
  if (!comp_topic_rclcpp__msg__PointDetect__are_equal(
      &(lhs->left2), &(rhs->left2)))
  {
    return false;
  }
  // right2
  if (!comp_topic_rclcpp__msg__PointDetect__are_equal(
      &(lhs->right2), &(rhs->right2)))
  {
    return false;
  }
  return true;
}

bool
comp_topic_rclcpp__msg__LinesResult__copy(
  const comp_topic_rclcpp__msg__LinesResult * input,
  comp_topic_rclcpp__msg__LinesResult * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // left1
  if (!comp_topic_rclcpp__msg__PointDetect__copy(
      &(input->left1), &(output->left1)))
  {
    return false;
  }
  // right1
  if (!comp_topic_rclcpp__msg__PointDetect__copy(
      &(input->right1), &(output->right1)))
  {
    return false;
  }
  // left2
  if (!comp_topic_rclcpp__msg__PointDetect__copy(
      &(input->left2), &(output->left2)))
  {
    return false;
  }
  // right2
  if (!comp_topic_rclcpp__msg__PointDetect__copy(
      &(input->right2), &(output->right2)))
  {
    return false;
  }
  return true;
}

comp_topic_rclcpp__msg__LinesResult *
comp_topic_rclcpp__msg__LinesResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__LinesResult * msg = (comp_topic_rclcpp__msg__LinesResult *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__LinesResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_topic_rclcpp__msg__LinesResult));
  bool success = comp_topic_rclcpp__msg__LinesResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_topic_rclcpp__msg__LinesResult__destroy(comp_topic_rclcpp__msg__LinesResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_topic_rclcpp__msg__LinesResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_topic_rclcpp__msg__LinesResult__Sequence__init(comp_topic_rclcpp__msg__LinesResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__LinesResult * data = NULL;

  if (size) {
    data = (comp_topic_rclcpp__msg__LinesResult *)allocator.zero_allocate(size, sizeof(comp_topic_rclcpp__msg__LinesResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_topic_rclcpp__msg__LinesResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_topic_rclcpp__msg__LinesResult__fini(&data[i - 1]);
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
comp_topic_rclcpp__msg__LinesResult__Sequence__fini(comp_topic_rclcpp__msg__LinesResult__Sequence * array)
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
      comp_topic_rclcpp__msg__LinesResult__fini(&array->data[i]);
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

comp_topic_rclcpp__msg__LinesResult__Sequence *
comp_topic_rclcpp__msg__LinesResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__LinesResult__Sequence * array = (comp_topic_rclcpp__msg__LinesResult__Sequence *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__LinesResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_topic_rclcpp__msg__LinesResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_topic_rclcpp__msg__LinesResult__Sequence__destroy(comp_topic_rclcpp__msg__LinesResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_topic_rclcpp__msg__LinesResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_topic_rclcpp__msg__LinesResult__Sequence__are_equal(const comp_topic_rclcpp__msg__LinesResult__Sequence * lhs, const comp_topic_rclcpp__msg__LinesResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_topic_rclcpp__msg__LinesResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_topic_rclcpp__msg__LinesResult__Sequence__copy(
  const comp_topic_rclcpp__msg__LinesResult__Sequence * input,
  comp_topic_rclcpp__msg__LinesResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_topic_rclcpp__msg__LinesResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_topic_rclcpp__msg__LinesResult * data =
      (comp_topic_rclcpp__msg__LinesResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_topic_rclcpp__msg__LinesResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_topic_rclcpp__msg__LinesResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_topic_rclcpp__msg__LinesResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
