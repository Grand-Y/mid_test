// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from comp_topic_rclcpp:msg/LinesResult.idl
// generated code does not contain a copyright notice
#include "comp_topic_rclcpp/msg/detail/lane_result__rosidl_typesupport_fastrtps_cpp.hpp"
#include "comp_topic_rclcpp/msg/detail/lane_result__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace comp_topic_rclcpp
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const comp_topic_rclcpp::msg::PointDetect &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  comp_topic_rclcpp::msg::PointDetect &);
size_t get_serialized_size(
  const comp_topic_rclcpp::msg::PointDetect &,
  size_t current_alignment);
size_t
max_serialized_size_PointDetect(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace comp_topic_rclcpp

// functions for comp_topic_rclcpp::msg::PointDetect already declared above

// functions for comp_topic_rclcpp::msg::PointDetect already declared above

// functions for comp_topic_rclcpp::msg::PointDetect already declared above


namespace comp_topic_rclcpp
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp
cdr_serialize(
  const comp_topic_rclcpp::msg::LinesResult & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: left1
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left1,
    cdr);
  // Member: right1
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right1,
    cdr);
  // Member: left2
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left2,
    cdr);
  // Member: right2
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right2,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  comp_topic_rclcpp::msg::LinesResult & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: left1
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left1);

  // Member: right1
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right1);

  // Member: left2
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left2);

  // Member: right2
  comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right2);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp
get_serialized_size(
  const comp_topic_rclcpp::msg::LinesResult & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: left1

  current_alignment +=
    comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left1, current_alignment);
  // Member: right1

  current_alignment +=
    comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right1, current_alignment);
  // Member: left2

  current_alignment +=
    comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left2, current_alignment);
  // Member: right2

  current_alignment +=
    comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right2, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp
max_serialized_size_LinesResult(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: left1
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::max_serialized_size_PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: right1
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::max_serialized_size_PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: left2
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::max_serialized_size_PointDetect(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: right2
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::max_serialized_size_PointDetect(
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
    using DataType = comp_topic_rclcpp::msg::LinesResult;
    is_plain =
      (
      offsetof(DataType, right2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _LinesResult__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const comp_topic_rclcpp::msg::LinesResult *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LinesResult__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<comp_topic_rclcpp::msg::LinesResult *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LinesResult__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const comp_topic_rclcpp::msg::LinesResult *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LinesResult__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LinesResult(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LinesResult__callbacks = {
  "comp_topic_rclcpp::msg",
  "LinesResult",
  _LinesResult__cdr_serialize,
  _LinesResult__cdr_deserialize,
  _LinesResult__get_serialized_size,
  _LinesResult__max_serialized_size
};

static rosidl_message_type_support_t _LinesResult__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LinesResult__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace comp_topic_rclcpp

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_topic_rclcpp
const rosidl_message_type_support_t *
get_message_type_support_handle<comp_topic_rclcpp::msg::LinesResult>()
{
  return &comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::_LinesResult__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, comp_topic_rclcpp, msg, LinesResult)() {
  return &comp_topic_rclcpp::msg::typesupport_fastrtps_cpp::_LinesResult__handle;
}

#ifdef __cplusplus
}
#endif