// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/PointDetect.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_topic_rclcpp/msg/detail/point_detect__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_topic_rclcpp
{

namespace msg
{

namespace builder
{

class Init_PointDetect_y
{
public:
  explicit Init_PointDetect_y(::comp_topic_rclcpp::msg::PointDetect & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::PointDetect y(::comp_topic_rclcpp::msg::PointDetect::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::PointDetect msg_;
};

class Init_PointDetect_x
{
public:
  Init_PointDetect_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointDetect_y x(::comp_topic_rclcpp::msg::PointDetect::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PointDetect_y(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::PointDetect msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::PointDetect>()
{
  return comp_topic_rclcpp::msg::builder::Init_PointDetect_x();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__BUILDER_HPP_
