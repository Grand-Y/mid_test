// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__TRAITS_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_topic_rclcpp/msg/detail/yolo_piece__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace comp_topic_rclcpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloPiece & msg,
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
    out << ", ";
  }

  // member: w
  {
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
    out << ", ";
  }

  // member: h
  {
    out << "h: ";
    rosidl_generator_traits::value_to_yaml(msg.h, out);
    out << ", ";
  }

  // member: prob
  {
    out << "prob: ";
    rosidl_generator_traits::value_to_yaml(msg.prob, out);
    out << ", ";
  }

  // member: obj_id
  {
    out << "obj_id: ";
    rosidl_generator_traits::value_to_yaml(msg.obj_id, out);
    out << ", ";
  }

  // member: track_id
  {
    out << "track_id: ";
    rosidl_generator_traits::value_to_yaml(msg.track_id, out);
    out << ", ";
  }

  // member: frames_counter
  {
    out << "frames_counter: ";
    rosidl_generator_traits::value_to_yaml(msg.frames_counter, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloPiece & msg,
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

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
    out << "\n";
  }

  // member: h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "h: ";
    rosidl_generator_traits::value_to_yaml(msg.h, out);
    out << "\n";
  }

  // member: prob
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prob: ";
    rosidl_generator_traits::value_to_yaml(msg.prob, out);
    out << "\n";
  }

  // member: obj_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obj_id: ";
    rosidl_generator_traits::value_to_yaml(msg.obj_id, out);
    out << "\n";
  }

  // member: track_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_id: ";
    rosidl_generator_traits::value_to_yaml(msg.track_id, out);
    out << "\n";
  }

  // member: frames_counter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frames_counter: ";
    rosidl_generator_traits::value_to_yaml(msg.frames_counter, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloPiece & msg, bool use_flow_style = false)
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
  const comp_topic_rclcpp::msg::YoloPiece & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_topic_rclcpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_topic_rclcpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_topic_rclcpp::msg::YoloPiece & msg)
{
  return comp_topic_rclcpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_topic_rclcpp::msg::YoloPiece>()
{
  return "comp_topic_rclcpp::msg::YoloPiece";
}

template<>
inline const char * name<comp_topic_rclcpp::msg::YoloPiece>()
{
  return "comp_topic_rclcpp/msg/YoloPiece";
}

template<>
struct has_fixed_size<comp_topic_rclcpp::msg::YoloPiece>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<comp_topic_rclcpp::msg::YoloPiece>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<comp_topic_rclcpp::msg::YoloPiece>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__TRAITS_HPP_
