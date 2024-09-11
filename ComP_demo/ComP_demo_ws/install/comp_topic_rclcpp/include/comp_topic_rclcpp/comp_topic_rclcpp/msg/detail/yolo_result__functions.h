// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__FUNCTIONS_H_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "comp_topic_rclcpp/msg/rosidl_generator_c__visibility_control.h"

#include "comp_topic_rclcpp/msg/detail/yolo_result__struct.h"

/// Initialize msg/YoloResult message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * comp_topic_rclcpp__msg__YoloResult
 * )) before or use
 * comp_topic_rclcpp__msg__YoloResult__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__init(comp_topic_rclcpp__msg__YoloResult * msg);

/// Finalize msg/YoloResult message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
void
comp_topic_rclcpp__msg__YoloResult__fini(comp_topic_rclcpp__msg__YoloResult * msg);

/// Create msg/YoloResult message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * comp_topic_rclcpp__msg__YoloResult__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
comp_topic_rclcpp__msg__YoloResult *
comp_topic_rclcpp__msg__YoloResult__create();

/// Destroy msg/YoloResult message.
/**
 * It calls
 * comp_topic_rclcpp__msg__YoloResult__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
void
comp_topic_rclcpp__msg__YoloResult__destroy(comp_topic_rclcpp__msg__YoloResult * msg);

/// Check for msg/YoloResult message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__are_equal(const comp_topic_rclcpp__msg__YoloResult * lhs, const comp_topic_rclcpp__msg__YoloResult * rhs);

/// Copy a msg/YoloResult message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__copy(
  const comp_topic_rclcpp__msg__YoloResult * input,
  comp_topic_rclcpp__msg__YoloResult * output);

/// Initialize array of msg/YoloResult messages.
/**
 * It allocates the memory for the number of elements and calls
 * comp_topic_rclcpp__msg__YoloResult__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__Sequence__init(comp_topic_rclcpp__msg__YoloResult__Sequence * array, size_t size);

/// Finalize array of msg/YoloResult messages.
/**
 * It calls
 * comp_topic_rclcpp__msg__YoloResult__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
void
comp_topic_rclcpp__msg__YoloResult__Sequence__fini(comp_topic_rclcpp__msg__YoloResult__Sequence * array);

/// Create array of msg/YoloResult messages.
/**
 * It allocates the memory for the array and calls
 * comp_topic_rclcpp__msg__YoloResult__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
comp_topic_rclcpp__msg__YoloResult__Sequence *
comp_topic_rclcpp__msg__YoloResult__Sequence__create(size_t size);

/// Destroy array of msg/YoloResult messages.
/**
 * It calls
 * comp_topic_rclcpp__msg__YoloResult__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
void
comp_topic_rclcpp__msg__YoloResult__Sequence__destroy(comp_topic_rclcpp__msg__YoloResult__Sequence * array);

/// Check for msg/YoloResult message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__Sequence__are_equal(const comp_topic_rclcpp__msg__YoloResult__Sequence * lhs, const comp_topic_rclcpp__msg__YoloResult__Sequence * rhs);

/// Copy an array of msg/YoloResult messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_comp_topic_rclcpp
bool
comp_topic_rclcpp__msg__YoloResult__Sequence__copy(
  const comp_topic_rclcpp__msg__YoloResult__Sequence * input,
  comp_topic_rclcpp__msg__YoloResult__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__FUNCTIONS_H_
