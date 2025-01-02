// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_topic_rclcpp/msg/detail/yolo_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_topic_rclcpp
{

namespace msg
{

namespace builder
{

class Init_YoloResult_result_array
{
public:
  explicit Init_YoloResult_result_array(::comp_topic_rclcpp::msg::YoloResult & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::YoloResult result_array(::comp_topic_rclcpp::msg::YoloResult::_result_array_type arg)
  {
    msg_.result_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloResult msg_;
};

class Init_YoloResult_result_num
{
public:
  explicit Init_YoloResult_result_num(::comp_topic_rclcpp::msg::YoloResult & msg)
  : msg_(msg)
  {}
  Init_YoloResult_result_array result_num(::comp_topic_rclcpp::msg::YoloResult::_result_num_type arg)
  {
    msg_.result_num = std::move(arg);
    return Init_YoloResult_result_array(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloResult msg_;
};

class Init_YoloResult_header
{
public:
  Init_YoloResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloResult_result_num header(::comp_topic_rclcpp::msg::YoloResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_YoloResult_result_num(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::YoloResult>()
{
  return comp_topic_rclcpp::msg::builder::Init_YoloResult_header();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_
