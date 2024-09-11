// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_H_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/YoloPiece in the package comp_topic_rclcpp.
typedef struct comp_topic_rclcpp__msg__YoloPiece
{
  double x;
  double y;
  double w;
  double h;
  float prob;
  int32_t obj_id;
  int32_t track_id;
  int32_t frames_counter;
} comp_topic_rclcpp__msg__YoloPiece;

// Struct for a sequence of comp_topic_rclcpp__msg__YoloPiece.
typedef struct comp_topic_rclcpp__msg__YoloPiece__Sequence
{
  comp_topic_rclcpp__msg__YoloPiece * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_topic_rclcpp__msg__YoloPiece__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_H_
