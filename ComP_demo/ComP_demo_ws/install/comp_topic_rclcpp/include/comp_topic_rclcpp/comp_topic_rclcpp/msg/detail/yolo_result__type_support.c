// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_topic_rclcpp:msg/YoloResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_topic_rclcpp/msg/detail/yolo_result__rosidl_typesupport_introspection_c.h"
#include "comp_topic_rclcpp/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_topic_rclcpp/msg/detail/yolo_result__functions.h"
#include "comp_topic_rclcpp/msg/detail/yolo_result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `result_array`
#include "comp_topic_rclcpp/msg/yolo_piece.h"
// Member `result_array`
#include "comp_topic_rclcpp/msg/detail/yolo_piece__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_topic_rclcpp__msg__YoloResult__init(message_memory);
}

void comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_fini_function(void * message_memory)
{
  comp_topic_rclcpp__msg__YoloResult__fini(message_memory);
}

size_t comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__size_function__YoloResult__result_array(
  const void * untyped_member)
{
  const comp_topic_rclcpp__msg__YoloPiece__Sequence * member =
    (const comp_topic_rclcpp__msg__YoloPiece__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_const_function__YoloResult__result_array(
  const void * untyped_member, size_t index)
{
  const comp_topic_rclcpp__msg__YoloPiece__Sequence * member =
    (const comp_topic_rclcpp__msg__YoloPiece__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_function__YoloResult__result_array(
  void * untyped_member, size_t index)
{
  comp_topic_rclcpp__msg__YoloPiece__Sequence * member =
    (comp_topic_rclcpp__msg__YoloPiece__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__fetch_function__YoloResult__result_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const comp_topic_rclcpp__msg__YoloPiece * item =
    ((const comp_topic_rclcpp__msg__YoloPiece *)
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_const_function__YoloResult__result_array(untyped_member, index));
  comp_topic_rclcpp__msg__YoloPiece * value =
    (comp_topic_rclcpp__msg__YoloPiece *)(untyped_value);
  *value = *item;
}

void comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__assign_function__YoloResult__result_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  comp_topic_rclcpp__msg__YoloPiece * item =
    ((comp_topic_rclcpp__msg__YoloPiece *)
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_function__YoloResult__result_array(untyped_member, index));
  const comp_topic_rclcpp__msg__YoloPiece * value =
    (const comp_topic_rclcpp__msg__YoloPiece *)(untyped_value);
  *item = *value;
}

bool comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__resize_function__YoloResult__result_array(
  void * untyped_member, size_t size)
{
  comp_topic_rclcpp__msg__YoloPiece__Sequence * member =
    (comp_topic_rclcpp__msg__YoloPiece__Sequence *)(untyped_member);
  comp_topic_rclcpp__msg__YoloPiece__Sequence__fini(member);
  return comp_topic_rclcpp__msg__YoloPiece__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__YoloResult, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__YoloResult, result_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_topic_rclcpp__msg__YoloResult, result_array),  // bytes offset in struct
    NULL,  // default value
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__size_function__YoloResult__result_array,  // size() function pointer
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_const_function__YoloResult__result_array,  // get_const(index) function pointer
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__get_function__YoloResult__result_array,  // get(index) function pointer
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__fetch_function__YoloResult__result_array,  // fetch(index, &value) function pointer
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__assign_function__YoloResult__result_array,  // assign(index, value) function pointer
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__resize_function__YoloResult__result_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_members = {
  "comp_topic_rclcpp__msg",  // message namespace
  "YoloResult",  // message name
  3,  // number of fields
  sizeof(comp_topic_rclcpp__msg__YoloResult),
  comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_member_array,  // message members
  comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_type_support_handle = {
  0,
  &comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_topic_rclcpp
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_topic_rclcpp, msg, YoloResult)() {
  comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_topic_rclcpp, msg, YoloPiece)();
  if (!comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_type_support_handle.typesupport_identifier) {
    comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_topic_rclcpp__msg__YoloResult__rosidl_typesupport_introspection_c__YoloResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
