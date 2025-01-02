// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_HPP_
#define COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__comp_topic_rclcpp__msg__YoloPiece __attribute__((deprecated))
#else
# define DEPRECATED__comp_topic_rclcpp__msg__YoloPiece __declspec(deprecated)
#endif

namespace comp_topic_rclcpp
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloPiece_
{
  using Type = YoloPiece_<ContainerAllocator>;

  explicit YoloPiece_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->w = 0.0;
      this->h = 0.0;
      this->prob = 0.0f;
      this->obj_id = 0l;
      this->track_id = 0l;
      this->frames_counter = 0l;
    }
  }

  explicit YoloPiece_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->w = 0.0;
      this->h = 0.0;
      this->prob = 0.0f;
      this->obj_id = 0l;
      this->track_id = 0l;
      this->frames_counter = 0l;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _w_type =
    double;
  _w_type w;
  using _h_type =
    double;
  _h_type h;
  using _prob_type =
    float;
  _prob_type prob;
  using _obj_id_type =
    int32_t;
  _obj_id_type obj_id;
  using _track_id_type =
    int32_t;
  _track_id_type track_id;
  using _frames_counter_type =
    int32_t;
  _frames_counter_type frames_counter;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__w(
    const double & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__h(
    const double & _arg)
  {
    this->h = _arg;
    return *this;
  }
  Type & set__prob(
    const float & _arg)
  {
    this->prob = _arg;
    return *this;
  }
  Type & set__obj_id(
    const int32_t & _arg)
  {
    this->obj_id = _arg;
    return *this;
  }
  Type & set__track_id(
    const int32_t & _arg)
  {
    this->track_id = _arg;
    return *this;
  }
  Type & set__frames_counter(
    const int32_t & _arg)
  {
    this->frames_counter = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_topic_rclcpp__msg__YoloPiece
    std::shared_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_topic_rclcpp__msg__YoloPiece
    std::shared_ptr<comp_topic_rclcpp::msg::YoloPiece_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloPiece_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->h != other.h) {
      return false;
    }
    if (this->prob != other.prob) {
      return false;
    }
    if (this->obj_id != other.obj_id) {
      return false;
    }
    if (this->track_id != other.track_id) {
      return false;
    }
    if (this->frames_counter != other.frames_counter) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloPiece_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloPiece_

// alias to use template instance with default allocator
using YoloPiece =
  comp_topic_rclcpp::msg::YoloPiece_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace comp_topic_rclcpp

#endif  // COMP_TOPIC_RCLCPP__MSG__DETAIL__YOLO_PIECE__STRUCT_HPP_
