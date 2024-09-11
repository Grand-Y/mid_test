// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from comp_topic_rclcpp:msg/LinesResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "comp_topic_rclcpp/msg/detail/lane_result__struct.hpp"
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

void LinesResult_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) comp_topic_rclcpp::msg::LinesResult(_init);
}

void LinesResult_fini_function(void * message_memory)
{
  auto typed_message = static_cast<comp_topic_rclcpp::msg::LinesResult *>(message_memory);
  typed_message->~LinesResult();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LinesResult_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::LinesResult, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_topic_rclcpp::msg::PointDetect>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::LinesResult, left1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_topic_rclcpp::msg::PointDetect>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::LinesResult, right1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_topic_rclcpp::msg::PointDetect>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::LinesResult, left2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_topic_rclcpp::msg::PointDetect>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp::msg::LinesResult, right2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LinesResult_message_members = {
  "comp_topic_rclcpp::msg",  // message namespace
  "LinesResult",  // message name
  5,  // number of fields
  sizeof(comp_topic_rclcpp::msg::LinesResult),
  LinesResult_message_member_array,  // message members
  LinesResult_init_function,  // function to initialize message memory (memory has to be allocated)
  LinesResult_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LinesResult_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LinesResult_message_members,
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
get_message_type_support_handle<comp_topic_rclcpp::msg::LinesResult>()
{
  return &::comp_topic_rclcpp::msg::rosidl_typesupport_introspection_cpp::LinesResult_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, comp_topic_rclcpp, msg, LinesResult)() {
  return &::comp_topic_rclcpp::msg::rosidl_typesupport_introspection_cpp::LinesResult_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
