// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_topic_rclcpp:msg/PointDetect.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__STRUCT_H_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PointDetect in the package comp_topic_rclcpp.
typedef struct comp_topic_rclcpp__msg__PointDetect
{
  int32_t x;
  int32_t y;
} comp_topic_rclcpp__msg__PointDetect;

// Struct for a sequence of comp_topic_rclcpp__msg__PointDetect.
typedef struct comp_topic_rclcpp__msg__PointDetect__Sequence
{
  comp_topic_rclcpp__msg__PointDetect * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_topic_rclcpp__msg__PointDetect__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__STRUCT_H_
