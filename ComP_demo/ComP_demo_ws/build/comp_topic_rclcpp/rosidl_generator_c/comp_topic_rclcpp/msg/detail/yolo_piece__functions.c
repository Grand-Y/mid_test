// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice
#include "comp_topic_rclcpp/msg/detail/yolo_piece__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
comp_topic_rclcpp__msg__YoloPiece__init(comp_topic_rclcpp__msg__YoloPiece * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // w
  // h
  // prob
  // obj_id
  // track_id
  // frames_counter
  return true;
}

void
comp_topic_rclcpp__msg__YoloPiece__fini(comp_topic_rclcpp__msg__YoloPiece * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // w
  // h
  // prob
  // obj_id
  // track_id
  // frames_counter
}

bool
comp_topic_rclcpp__msg__YoloPiece__are_equal(const comp_topic_rclcpp__msg__YoloPiece * lhs, const comp_topic_rclcpp__msg__YoloPiece * rhs)
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
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  // h
  if (lhs->h != rhs->h) {
    return false;
  }
  // prob
  if (lhs->prob != rhs->prob) {
    return false;
  }
  // obj_id
  if (lhs->obj_id != rhs->obj_id) {
    return false;
  }
  // track_id
  if (lhs->track_id != rhs->track_id) {
    return false;
  }
  // frames_counter
  if (lhs->frames_counter != rhs->frames_counter) {
    return false;
  }
  return true;
}

bool
comp_topic_rclcpp__msg__YoloPiece__copy(
  const comp_topic_rclcpp__msg__YoloPiece * input,
  comp_topic_rclcpp__msg__YoloPiece * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // w
  output->w = input->w;
  // h
  output->h = input->h;
  // prob
  output->prob = input->prob;
  // obj_id
  output->obj_id = input->obj_id;
  // track_id
  output->track_id = input->track_id;
  // frames_counter
  output->frames_counter = input->frames_counter;
  return true;
}

comp_topic_rclcpp__msg__YoloPiece *
comp_topic_rclcpp__msg__YoloPiece__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__YoloPiece * msg = (comp_topic_rclcpp__msg__YoloPiece *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__YoloPiece), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_topic_rclcpp__msg__YoloPiece));
  bool success = comp_topic_rclcpp__msg__YoloPiece__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_topic_rclcpp__msg__YoloPiece__destroy(comp_topic_rclcpp__msg__YoloPiece * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_topic_rclcpp__msg__YoloPiece__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_topic_rclcpp__msg__YoloPiece__Sequence__init(comp_topic_rclcpp__msg__YoloPiece__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__YoloPiece * data = NULL;

  if (size) {
    data = (comp_topic_rclcpp__msg__YoloPiece *)allocator.zero_allocate(size, sizeof(comp_topic_rclcpp__msg__YoloPiece), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_topic_rclcpp__msg__YoloPiece__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_topic_rclcpp__msg__YoloPiece__fini(&data[i - 1]);
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
comp_topic_rclcpp__msg__YoloPiece__Sequence__fini(comp_topic_rclcpp__msg__YoloPiece__Sequence * array)
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
      comp_topic_rclcpp__msg__YoloPiece__fini(&array->data[i]);
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

comp_topic_rclcpp__msg__YoloPiece__Sequence *
comp_topic_rclcpp__msg__YoloPiece__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_topic_rclcpp__msg__YoloPiece__Sequence * array = (comp_topic_rclcpp__msg__YoloPiece__Sequence *)allocator.allocate(sizeof(comp_topic_rclcpp__msg__YoloPiece__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_topic_rclcpp__msg__YoloPiece__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_topic_rclcpp__msg__YoloPiece__Sequence__destroy(comp_topic_rclcpp__msg__YoloPiece__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_topic_rclcpp__msg__YoloPiece__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_topic_rclcpp__msg__YoloPiece__Sequence__are_equal(const comp_topic_rclcpp__msg__YoloPiece__Sequence * lhs, const comp_topic_rclcpp__msg__YoloPiece__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_topic_rclcpp__msg__YoloPiece__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_topic_rclcpp__msg__YoloPiece__Sequence__copy(
  const comp_topic_rclcpp__msg__YoloPiece__Sequence * input,
  comp_topic_rclcpp__msg__YoloPiece__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_topic_rclcpp__msg__YoloPiece);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_topic_rclcpp__msg__YoloPiece * data =
      (comp_topic_rclcpp__msg__YoloPiece *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_topic_rclcpp__msg__YoloPiece__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_topic_rclcpp__msg__YoloPiece__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_topic_rclcpp__msg__YoloPiece__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
