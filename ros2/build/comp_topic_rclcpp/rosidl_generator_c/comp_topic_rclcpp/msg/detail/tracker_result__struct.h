// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_topic_rclcpp:msg/TrackerResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__STRUCT_H_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'x'
// Member 'y'
// Member 'width'
// Member 'height'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TrackerResult in the package comp_topic_rclcpp.
typedef struct comp_topic_rclcpp__msg__TrackerResult
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
  rosidl_runtime_c__double__Sequence width;
  rosidl_runtime_c__double__Sequence height;
} comp_topic_rclcpp__msg__TrackerResult;

// Struct for a sequence of comp_topic_rclcpp__msg__TrackerResult.
typedef struct comp_topic_rclcpp__msg__TrackerResult__Sequence
{
  comp_topic_rclcpp__msg__TrackerResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_topic_rclcpp__msg__TrackerResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__STRUCT_H_
