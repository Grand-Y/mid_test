// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_topic_rclcpp:msg/LaneResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__TRAITS_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_topic_rclcpp/msg/detail/lane_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left1'
// Member 'right1'
// Member 'left2'
// Member 'right2'
#include "comp_topic_rclcpp/msg/detail/point_detect__traits.hpp"

namespace comp_topic_rclcpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaneResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left1
  {
    out << "left1: ";
    to_flow_style_yaml(msg.left1, out);
    out << ", ";
  }

  // member: right1
  {
    out << "right1: ";
    to_flow_style_yaml(msg.right1, out);
    out << ", ";
  }

  // member: left2
  {
    out << "left2: ";
    to_flow_style_yaml(msg.left2, out);
    out << ", ";
  }

  // member: right2
  {
    out << "right2: ";
    to_flow_style_yaml(msg.right2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaneResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left1:\n";
    to_block_style_yaml(msg.left1, out, indentation + 2);
  }

  // member: right1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right1:\n";
    to_block_style_yaml(msg.right1, out, indentation + 2);
  }

  // member: left2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left2:\n";
    to_block_style_yaml(msg.left2, out, indentation + 2);
  }

  // member: right2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right2:\n";
    to_block_style_yaml(msg.right2, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaneResult & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace comp_topic_rclcpp

namespace rosidl_generator_traits
{

[[deprecated("use comp_topic_rclcpp::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_topic_rclcpp::msg::LaneResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_topic_rclcpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_topic_rclcpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_topic_rclcpp::msg::LaneResult & msg)
{
  return comp_topic_rclcpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_topic_rclcpp::msg::LaneResult>()
{
  return "comp_topic_rclcpp::msg::LaneResult";
}

template<>
inline const char * name<comp_topic_rclcpp::msg::LaneResult>()
{
  return "comp_topic_rclcpp/msg/LaneResult";
}

template<>
struct has_fixed_size<comp_topic_rclcpp::msg::LaneResult>
  : std::integral_constant<bool, has_fixed_size<comp_topic_rclcpp::msg::PointDetect>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<comp_topic_rclcpp::msg::LaneResult>
  : std::integral_constant<bool, has_bounded_size<comp_topic_rclcpp::msg::PointDetect>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<comp_topic_rclcpp::msg::LaneResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__LANE_RESULT__TRAITS_HPP_
