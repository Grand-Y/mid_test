// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_topic_rclcpp:msg/PointDetect.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__TRAITS_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_topic_rclcpp/msg/detail/point_detect__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace comp_topic_rclcpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const PointDetect & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointDetect & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointDetect & msg, bool use_flow_style = false)
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
  const comp_topic_rclcpp::msg::PointDetect & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_topic_rclcpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_topic_rclcpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_topic_rclcpp::msg::PointDetect & msg)
{
  return comp_topic_rclcpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_topic_rclcpp::msg::PointDetect>()
{
  return "comp_topic_rclcpp::msg::PointDetect";
}

template<>
inline const char * name<comp_topic_rclcpp::msg::PointDetect>()
{
  return "comp_topic_rclcpp/msg/PointDetect";
}

template<>
struct has_fixed_size<comp_topic_rclcpp::msg::PointDetect>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<comp_topic_rclcpp::msg::PointDetect>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<comp_topic_rclcpp::msg::PointDetect>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__POINT_DETECT__TRAITS_HPP_
