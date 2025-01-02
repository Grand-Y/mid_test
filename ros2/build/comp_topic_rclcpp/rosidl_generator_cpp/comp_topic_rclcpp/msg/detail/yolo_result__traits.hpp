// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_topic_rclcpp/msg/detail/yolo_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'result_array'
#include "comp_topic_rclcpp/msg/detail/yolo_piece__traits.hpp"

namespace comp_topic_rclcpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: result_num
  {
    out << "result_num: ";
    rosidl_generator_traits::value_to_yaml(msg.result_num, out);
    out << ", ";
  }

  // member: result_array
  {
    if (msg.result_array.size() == 0) {
      out << "result_array: []";
    } else {
      out << "result_array: [";
      size_t pending_items = msg.result_array.size();
      for (auto item : msg.result_array) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloResult & msg,
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

  // member: result_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_num: ";
    rosidl_generator_traits::value_to_yaml(msg.result_num, out);
    out << "\n";
  }

  // member: result_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.result_array.size() == 0) {
      out << "result_array: []\n";
    } else {
      out << "result_array:\n";
      for (auto item : msg.result_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloResult & msg, bool use_flow_style = false)
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
  const comp_topic_rclcpp::msg::YoloResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_topic_rclcpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_topic_rclcpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_topic_rclcpp::msg::YoloResult & msg)
{
  return comp_topic_rclcpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_topic_rclcpp::msg::YoloResult>()
{
  return "comp_topic_rclcpp::msg::YoloResult";
}

template<>
inline const char * name<comp_topic_rclcpp::msg::YoloResult>()
{
  return "comp_topic_rclcpp/msg/YoloResult";
}

template<>
struct has_fixed_size<comp_topic_rclcpp::msg::YoloResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<comp_topic_rclcpp::msg::YoloResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<comp_topic_rclcpp::msg::YoloResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_
