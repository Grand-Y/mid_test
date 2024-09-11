// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "comp_topic_rclcpp/msg/detail/yolo_result__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace comp_topic_rclcpp
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void YoloResult_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) comp_topic_rclcpp::msg::YoloResult(_init);
}

void YoloResult_fini_function(void * message_memory)
{
  auto typed_message = static_cast<comp_topic_rclcpp::msg::YoloResult *>(message_memory);
  typed_message->~YoloResult();
}

size_t size_function__YoloResult__result_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<comp_topic_rclcpp::msg::YoloPiece> *>(untyped_member);
  return member->size();
}

const void * get_const_function__YoloResult__result_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<comp_topic_rclcpp::msg::YoloPiece> *>(untyped_member);
  return &member[index];
}

void * get_function__YoloResult__result_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<comp_topic_rclcpp::msg::YoloPiece> *>(untyped_member);
  return &member[index];
}

void fetch_function__YoloResult__result_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const comp_topic_rclcpp::msg::YoloPiece *>(
    get_const_function__YoloResult__result_array(untyped_member, index));
  auto & value = *reinterpret_cast<comp_topic_rclcpp::msg::YoloPiece *>(untyped_value);
  value = item;
}

void assign_function__YoloResult__result_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<comp_topic_rclcpp::msg::YoloPiece *>(
    get_function__YoloResult__result_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const comp_topic_rclcpp::msg::YoloPiece *>(untyped_value);
  item = value;
}

void resize_function__YoloResult__result_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<comp_topic_rclcpp::msg::YoloPiece> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember YoloResult_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::YoloResult, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result_num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::YoloResult, result_num),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_topic_rclcpp::msg::YoloPiece>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::YoloResult, result_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__YoloResult__result_array,  // size() function pointer
    get_const_function__YoloResult__result_array,  // get_const(index) function pointer
    get_function__YoloResult__result_array,  // get(index) function pointer
    fetch_function__YoloResult__result_array,  // fetch(index, &value) function pointer
    assign_function__YoloResult__result_array,  // assign(index, value) function pointer
    resize_function__YoloResult__result_array  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers YoloResult_message_members = {
  "comp_topic_rclcpp::msg",  // message namespace
  "YoloResult",  // message name
  3,  // number of fields
  sizeof(comp_topic_rclcpp::msg::YoloResult),
  YoloResult_message_member_array,  // message members
  YoloResult_init_function,  // function to initialize message memory (memory has to be allocated)
  YoloResult_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t YoloResult_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &YoloResult_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace comp_topic_rclcpp


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<comp_topic_rclcpp::msg::YoloResult>()
{
  return &::comp_topic_rclcpp::msg::rosidl_typesupport_introspection_cpp::YoloResult_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, comp_topic_rclcpp, msg, YoloResult)() {
  return &::comp_topic_rclcpp::msg::rosidl_typesupport_introspection_cpp::YoloResult_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
