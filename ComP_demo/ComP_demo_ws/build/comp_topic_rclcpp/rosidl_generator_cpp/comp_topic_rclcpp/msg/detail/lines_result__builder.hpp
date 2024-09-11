// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/LinesResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_topic_rclcpp/msg/detail/lane_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_topic_rclcpp
{

namespace msg
{

namespace builder
{

class Init_LinesResult_right2
{
public:
  explicit Init_LinesResult_right2(::comp_topic_rclcpp::msg::LinesResult & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::LinesResult right2(::comp_topic_rclcpp::msg::LinesResult::_right2_type arg)
  {
    msg_.right2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LinesResult msg_;
};

class Init_LinesResult_left2
{
public:
  explicit Init_LinesResult_left2(::comp_topic_rclcpp::msg::LinesResult & msg)
  : msg_(msg)
  {}
  Init_LinesResult_right2 left2(::comp_topic_rclcpp::msg::LinesResult::_left2_type arg)
  {
    msg_.left2 = std::move(arg);
    return Init_LinesResult_right2(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LinesResult msg_;
};

class Init_LinesResult_right1
{
public:
  explicit Init_LinesResult_right1(::comp_topic_rclcpp::msg::LinesResult & msg)
  : msg_(msg)
  {}
  Init_LinesResult_left2 right1(::comp_topic_rclcpp::msg::LinesResult::_right1_type arg)
  {
    msg_.right1 = std::move(arg);
    return Init_LinesResult_left2(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LinesResult msg_;
};

class Init_LinesResult_left1
{
public:
  explicit Init_LinesResult_left1(::comp_topic_rclcpp::msg::LinesResult & msg)
  : msg_(msg)
  {}
  Init_LinesResult_right1 left1(::comp_topic_rclcpp::msg::LinesResult::_left1_type arg)
  {
    msg_.left1 = std::move(arg);
    return Init_LinesResult_right1(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LinesResult msg_;
};

class Init_LinesResult_header
{
public:
  Init_LinesResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LinesResult_left1 header(::comp_topic_rclcpp::msg::LinesResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LinesResult_left1(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LinesResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::LinesResult>()
{
  return comp_topic_rclcpp::msg::builder::Init_LinesResult_header();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__BUILDER_HPP_
