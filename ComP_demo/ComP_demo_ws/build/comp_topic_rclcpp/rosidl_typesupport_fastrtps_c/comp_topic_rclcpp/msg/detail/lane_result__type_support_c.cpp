// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from comp_topic_rclcpp:msg/LaneResult.idl
// generated code does not contain a copyright notice
#include "comp_topic_rclcpp/msg/detail/lane_result__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "comp_topic_rclcpp/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "comp_topic_rclcpp/msg/detail/lane_result__struct.h"
#include "comp_topic_rclcpp/msg/detail/lane_result__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "comp_topic_rclcpp/msg/detail/point_detect__functions.h"  // left1, left2, right1, right2
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_comp_topic_rclcpp__msg__PointDetect(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_comp_topic_rclcpp__msg__PointDetect(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_topic_rclcpp
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_topic_rclcpp
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_topic_rclcpp
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _LaneResult__ros_msg_type = comp_topic_rclcpp__msg__LaneResult;

static bool _LaneResult__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LaneResult__ros_msg_type * ros_message = static_cast<const _LaneResult__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: left1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->left1, cdr))
    {
      return false;
    }
  }

  // Field name: right1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->right1, cdr))
    {
      return false;
    }
  }

  // Field name: left2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->left2, cdr))
    {
      return false;
    }
  }

  // Field name: right2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->right2, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _LaneResult__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LaneResult__ros_msg_type * ros_message = static_cast<_LaneResult__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: left1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->left1))
    {
      return false;
    }
  }

  // Field name: right1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->right1))
    {
      return false;
    }
  }

  // Field name: left2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->left2))
    {
      return false;
    }
  }

  // Field name: right2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, PointDetect
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->right2))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_comp_topic_rclcpp
size_t get_serialized_size_comp_topic_rclcpp__msg__LaneResult(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaneResult__ros_msg_type * ros_message = static_cast<const _LaneResult__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name left1

  current_alignment += get_serialized_size_comp_topic_rclcpp__msg__PointDetect(
    &(ros_message->left1), current_alignment);
  // field.name right1

  current_alignment += get_serialized_size_comp_topic_rclcpp__msg__PointDetect(
    &(ros_message->right1), current_alignment);
  // field.name left2

  current_alignment += get_serialized_size_comp_topic_rclcpp__msg__PointDetect(
    &(ros_message->left2), current_alignment);
  // field.name right2

  current_alignment += get_serialized_size_comp_topic_rclcpp__msg__PointDetect(
    &(ros_message->right2), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LaneResult__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_comp_topic_rclcpp__msg__LaneResult(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_comp_topic_rclcpp
size_t max_serialized_size_comp_topic_rclcpp__msg__LaneResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: left1
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_comp_topic_rclcpp__msg__PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: right1
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_comp_topic_rclcpp__msg__PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: left2
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_comp_topic_rclcpp__msg__PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: right2
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_comp_topic_rclcpp__msg__PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = comp_topic_rclcpp__msg__LaneResult;
    is_plain =
      (
      offsetof(DataType, right2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LaneResult__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_comp_topic_rclcpp__msg__LaneResult(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LaneResult = {
  "comp_topic_rclcpp::msg",
  "LaneResult",
  _LaneResult__cdr_serialize,
  _LaneResult__cdr_deserialize,
  _LaneResult__get_serialized_size,
  _LaneResult__max_serialized_size
};

static rosidl_message_type_support_t _LaneResult__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LaneResult,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_topic_rclcpp, msg, LaneResult)() {
  return &_LaneResult__type_support;
}

#if defined(__cplusplus)
}
#endif
