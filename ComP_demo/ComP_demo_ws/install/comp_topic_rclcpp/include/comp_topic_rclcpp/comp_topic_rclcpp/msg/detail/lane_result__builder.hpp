// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/LaneResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__BUILDER_HPP_

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

class Init_LaneResult_right2
{
public:
  explicit Init_LaneResult_right2(::comp_topic_rclcpp::msg::LaneResult & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::LaneResult right2(::comp_topic_rclcpp::msg::LaneResult::_right2_type arg)
  {
    msg_.right2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LaneResult msg_;
};

class Init_LaneResult_left2
{
public:
  explicit Init_LaneResult_left2(::comp_topic_rclcpp::msg::LaneResult & msg)
  : msg_(msg)
  {}
  Init_LaneResult_right2 left2(::comp_topic_rclcpp::msg::LaneResult::_left2_type arg)
  {
    msg_.left2 = std::move(arg);
    return Init_LaneResult_right2(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LaneResult msg_;
};

class Init_LaneResult_right1
{
public:
  explicit Init_LaneResult_right1(::comp_topic_rclcpp::msg::LaneResult & msg)
  : msg_(msg)
  {}
  Init_LaneResult_left2 right1(::comp_topic_rclcpp::msg::LaneResult::_right1_type arg)
  {
    msg_.right1 = std::move(arg);
    return Init_LaneResult_left2(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LaneResult msg_;
};

class Init_LaneResult_left1
{
public:
  explicit Init_LaneResult_left1(::comp_topic_rclcpp::msg::LaneResult & msg)
  : msg_(msg)
  {}
  Init_LaneResult_right1 left1(::comp_topic_rclcpp::msg::LaneResult::_left1_type arg)
  {
    msg_.left1 = std::move(arg);
    return Init_LaneResult_right1(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LaneResult msg_;
};

class Init_LaneResult_header
{
public:
  Init_LaneResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneResult_left1 header(::comp_topic_rclcpp::msg::LaneResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LaneResult_left1(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::LaneResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::LaneResult>()
{
  return comp_topic_rclcpp::msg::builder::Init_LaneResult_header();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__BUILDER_HPP_
