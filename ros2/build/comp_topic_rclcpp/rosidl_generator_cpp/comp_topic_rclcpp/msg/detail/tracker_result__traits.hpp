// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_topic_rclcpp:msg/TrackerResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__TRAITS_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_topic_rclcpp/msg/detail/tracker_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace comp_topic_rclcpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrackerResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: width
  {
    if (msg.width.size() == 0) {
      out << "width: []";
    } else {
      out << "width: [";
      size_t pending_items = msg.width.size();
      for (auto item : msg.width) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: height
  {
    if (msg.height.size() == 0) {
      out << "height: []";
    } else {
      out << "height: [";
      size_t pending_items = msg.height.size();
      for (auto item : msg.height) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const TrackerResult & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.width.size() == 0) {
      out << "width: []\n";
    } else {
      out << "width:\n";
      for (auto item : msg.width) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.height.size() == 0) {
      out << "height: []\n";
    } else {
      out << "height:\n";
      for (auto item : msg.height) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackerResult & msg, bool use_flow_style = false)
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
  const comp_topic_rclcpp::msg::TrackerResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_topic_rclcpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_topic_rclcpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const comp_topic_rclcpp::msg::TrackerResult & msg)
{
  return comp_topic_rclcpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<comp_topic_rclcpp::msg::TrackerResult>()
{
  return "comp_topic_rclcpp::msg::TrackerResult";
}

template<>
inline const char * name<comp_topic_rclcpp::msg::TrackerResult>()
{
  return "comp_topic_rclcpp/msg/TrackerResult";
}

template<>
struct has_fixed_size<comp_topic_rclcpp::msg::TrackerResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<comp_topic_rclcpp::msg::TrackerResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<comp_topic_rclcpp::msg::TrackerResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__TRACKER_RESULT__TRAITS_HPP_
