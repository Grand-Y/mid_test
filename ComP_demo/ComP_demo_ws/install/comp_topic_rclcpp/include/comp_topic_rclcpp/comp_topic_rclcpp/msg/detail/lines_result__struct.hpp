// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_topic_rclcpp:msg/LinesResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__STRUCT_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'left1'
// Member 'right1'
// Member 'left2'
// Member 'right2'
#include "comp_topic_rclcpp/msg/detail/point_detect__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_topic_rclcpp__msg__LinesResult __attribute__((deprecated))
#else
# define DEPRECATED__comp_topic_rclcpp__msg__LinesResult __declspec(deprecated)
#endif

namespace comp_topic_rclcpp
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LinesResult_
{
  using Type = LinesResult_<ContainerAllocator>;

  explicit LinesResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    left1(_init),
    right1(_init),
    left2(_init),
    right2(_init)
  {
    (void)_init;
  }

  explicit LinesResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    left1(_alloc, _init),
    right1(_alloc, _init),
    left2(_alloc, _init),
    right2(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _left1_type =
    comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator>;
  _left1_type left1;
  using _right1_type =
    comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator>;
  _right1_type right1;
  using _left2_type =
    comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator>;
  _left2_type left2;
  using _right2_type =
    comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator>;
  _right2_type right2;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__left1(
    const comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator> & _arg)
  {
    this->left1 = _arg;
    return *this;
  }
  Type & set__right1(
    const comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator> & _arg)
  {
    this->right1 = _arg;
    return *this;
  }
  Type & set__left2(
    const comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator> & _arg)
  {
    this->left2 = _arg;
    return *this;
  }
  Type & set__right2(
    const comp_topic_rclcpp::msg::PointDetect_<ContainerAllocator> & _arg)
  {
    this->right2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_topic_rclcpp__msg__LinesResult
    std::shared_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_topic_rclcpp__msg__LinesResult
    std::shared_ptr<comp_topic_rclcpp::msg::LinesResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LinesResult_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->left1 != other.left1) {
      return false;
    }
    if (this->right1 != other.right1) {
      return false;
    }
    if (this->left2 != other.left2) {
      return false;
    }
    if (this->right2 != other.right2) {
      return false;
    }
    return true;
  }
  bool operator!=(const LinesResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LinesResult_

// alias to use template instance with default allocator
using LinesResult =
  comp_topic_rclcpp::msg::LinesResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__LINES_RESULT__STRUCT_HPP_
