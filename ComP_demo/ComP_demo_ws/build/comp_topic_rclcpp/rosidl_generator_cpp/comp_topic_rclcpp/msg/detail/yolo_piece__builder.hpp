// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__BUILDER_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_topic_rclcpp/msg/detail/yolo_piece__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_topic_rclcpp
{

namespace msg
{

namespace builder
{

class Init_YoloPiece_frames_counter
{
public:
  explicit Init_YoloPiece_frames_counter(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  ::comp_topic_rclcpp::msg::YoloPiece frames_counter(::comp_topic_rclcpp::msg::YoloPiece::_frames_counter_type arg)
  {
    msg_.frames_counter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_track_id
{
public:
  explicit Init_YoloPiece_track_id(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_frames_counter track_id(::comp_topic_rclcpp::msg::YoloPiece::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return Init_YoloPiece_frames_counter(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_obj_id
{
public:
  explicit Init_YoloPiece_obj_id(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_track_id obj_id(::comp_topic_rclcpp::msg::YoloPiece::_obj_id_type arg)
  {
    msg_.obj_id = std::move(arg);
    return Init_YoloPiece_track_id(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_prob
{
public:
  explicit Init_YoloPiece_prob(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_obj_id prob(::comp_topic_rclcpp::msg::YoloPiece::_prob_type arg)
  {
    msg_.prob = std::move(arg);
    return Init_YoloPiece_obj_id(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_h
{
public:
  explicit Init_YoloPiece_h(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_prob h(::comp_topic_rclcpp::msg::YoloPiece::_h_type arg)
  {
    msg_.h = std::move(arg);
    return Init_YoloPiece_prob(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_w
{
public:
  explicit Init_YoloPiece_w(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_h w(::comp_topic_rclcpp::msg::YoloPiece::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_YoloPiece_h(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_y
{
public:
  explicit Init_YoloPiece_y(::comp_topic_rclcpp::msg::YoloPiece & msg)
  : msg_(msg)
  {}
  Init_YoloPiece_w y(::comp_topic_rclcpp::msg::YoloPiece::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_YoloPiece_w(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

class Init_YoloPiece_x
{
public:
  Init_YoloPiece_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloPiece_y x(::comp_topic_rclcpp::msg::YoloPiece::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_YoloPiece_y(msg_);
  }

private:
  ::comp_topic_rclcpp::msg::YoloPiece msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_topic_rclcpp::msg::YoloPiece>()
{
  return comp_topic_rclcpp::msg::builder::Init_YoloPiece_x();
}

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__BUILDER_HPP_
