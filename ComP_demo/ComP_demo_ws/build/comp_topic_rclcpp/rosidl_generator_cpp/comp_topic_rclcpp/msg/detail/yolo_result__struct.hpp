// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_

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
// Member 'result_array'
#include "comp_topic_rclcpp/msg/detail/yolo_piece__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_topic_rclcpp__msg__YoloResult __attribute__((deprecated))
#else
# define DEPRECATED__comp_topic_rclcpp__msg__YoloResult __declspec(deprecated)
#endif

namespace comp_topic_rclcpp
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloResult_
{
  using Type = YoloResult_<ContainerAllocator>;

  explicit YoloResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_num = 0ul;
    }
  }

  explicit YoloResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_num = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _result_num_type =
    uint32_t;
  _result_num_type result_num;
  using _result_array_type =
    std::vector<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>>;
  _result_array_type result_array;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__result_num(
    const uint32_t & _arg)
  {
    this->result_num = _arg;
    return *this;
  }
  Type & set__result_array(
    const std::vector<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>> & _arg)
  {
    this->result_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_topic_rclcpp__msg__YoloResult
    std::shared_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_topic_rclcpp__msg__YoloResult
    std::shared_ptr<comp_topic_rclcpp::msg::YoloResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloResult_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->result_num != other.result_num) {
      return false;
    }
    if (this->result_array != other.result_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloResult_

// alias to use template instance with default allocator
using YoloResult =
  comp_topic_rclcpp::msg::YoloResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_
