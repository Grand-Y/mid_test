// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_topic_rclcpp:msg/PointDetect.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_topic_rclcpp/msg/detail/point_detect__rosidl_typesupport_introspection_c.h"
#include "comp_topic_rclcpp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_topic_rclcpp/msg/detail/point_detect__functions.h"
#include "comp_topic_rclcpp/msg/detail/point_detect__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_topic_rclcpp__msg__PointDetect__init(message_memory);
}

void comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_fini_function(void * message_memory)
{
  comp_topic_rclcpp__msg__PointDetect__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__PointDetect, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__PointDetect, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_members = {
  "comp_topic_rclcpp__msg",  // message namespace
  "PointDetect",  // message name
  2,  // number of fields
  sizeof(comp_topic_rclcpp__msg__PointDetect),
  comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_member_array,  // message members
  comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_type_support_handle = {
  0,
  &comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_topic_rclcpp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_topic_rclcpp, msg, PointDetect)() {
  if (!comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_type_support_handle.typesupport_identifier) {
    comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_topic_rclcpp__msg__PointDetect__rosidl_typesupport_introspection_c__PointDetect_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif