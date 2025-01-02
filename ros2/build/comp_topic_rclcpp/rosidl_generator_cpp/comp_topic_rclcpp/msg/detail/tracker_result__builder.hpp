// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/TrackerResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_topic_rclcpp/msg/detail/tracker_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_topic_rclcpp
{

namespace msg
{

namespace builder
{

class Init_TrackerResult_height
{
public:
  explicit Init_TrackerResult_height(::comp_topic_rclcpp::msg::TrackerResult & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::TrackerResult height(::comp_topic_rclcpp::msg::TrackerResult::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::TrackerResult msg_;
};

class Init_TrackerResult_width
{
public:
  explicit Init_TrackerResult_width(::comp_topic_rclcpp::msg::TrackerResult & msg)
  : msg_(msg)
  {}
  Init_TrackerResult_height width(::comp_topic_rclcpp::msg::TrackerResult::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_TrackerResult_height(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::TrackerResult msg_;
};

class Init_TrackerResult_y
{
public:
  explicit Init_TrackerResult_y(::comp_topic_rclcpp::msg::TrackerResult & msg)
  : msg_(msg)
  {}
  Init_TrackerResult_width y(::comp_topic_rclcpp::msg::TrackerResult::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TrackerResult_width(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::TrackerResult msg_;
};

class Init_TrackerResult_x
{
public:
  explicit Init_TrackerResult_x(::comp_topic_rclcpp::msg::TrackerResult & msg)
  : msg_(msg)
  {}
  Init_TrackerResult_y x(::comp_topic_rclcpp::msg::TrackerResult::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TrackerResult_y(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::TrackerResult msg_;
};

class Init_TrackerResult_header
{
public:
  Init_TrackerResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackerResult_x header(::comp_topic_rclcpp::msg::TrackerResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackerResult_x(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::TrackerResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::TrackerResult>()
{
  return comp_topic_rclcpp::msg::builder::Init_TrackerResult_header();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__BUILDER_HPP_
