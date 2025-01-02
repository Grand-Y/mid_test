// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_topic_rclcpp:msg/TrackerResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_topic_rclcpp/msg/detail/tracker_result__rosidl_typesupport_introspection_c.h"
#include "comp_topic_rclcpp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_topic_rclcpp/msg/detail/tracker_result__functions.h"
#include "comp_topic_rclcpp/msg/detail/tracker_result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `x`
// Member `y`
// Member `width`
// Member `height`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_topic_rclcpp__msg__TrackerResult__init(message_memory);
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_fini_function(void * message_memory)
{
  comp_topic_rclcpp__msg__TrackerResult__fini(message_memory);
}

size_t comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__width(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__width(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__width(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__width(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__width(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__width(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__width(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__width(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__height(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__height(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__height(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__height(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__height(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__height(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__height(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__height(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__TrackerResult, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__TrackerResult, x),  // bytes offset in struct
    NULL,  // default value
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__x,  // size() function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__x,  // get_const(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__x,  // get(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__x,  // fetch(index, &value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__x,  // assign(index, value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__TrackerResult, y),  // bytes offset in struct
    NULL,  // default value
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__y,  // size() function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__y,  // get_const(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__y,  // get(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__y,  // fetch(index, &value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__y,  // assign(index, value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__y  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__TrackerResult, width),  // bytes offset in struct
    NULL,  // default value
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__width,  // size() function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__width,  // get_const(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__width,  // get(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__width,  // fetch(index, &value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__width,  // assign(index, value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__width  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__TrackerResult, height),  // bytes offset in struct
    NULL,  // default value
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__size_function__TrackerResult__height,  // size() function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_const_function__TrackerResult__height,  // get_const(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__get_function__TrackerResult__height,  // get(index) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__fetch_function__TrackerResult__height,  // fetch(index, &value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__assign_function__TrackerResult__height,  // assign(index, value) function pointer
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__resize_function__TrackerResult__height  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_members = {
  "comp_topic_rclcpp__msg",  // message namespace
  "TrackerResult",  // message name
  5,  // number of fields
  sizeof(comp_topic_rclcpp__msg__TrackerResult),
  comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_member_array,  // message members
  comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_type_support_handle = {
  0,
  &comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_topic_rclcpp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_topic_rclcpp, msg, TrackerResult)() {
  comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_type_support_handle.typesupport_identifier) {
    comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_topic_rclcpp__msg__TrackerResult__rosidl_typesupport_introspection_c__TrackerResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
