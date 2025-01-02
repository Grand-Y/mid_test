// generated from
// rosidl_typesupport_fastrtps_cpp/resource/rosidl_typesupport_fastrtps_cpp__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef COMP_TOPIC_RCLCPP__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_
#define COMP_TOPIC_RCLCPP__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_topic_rclcpp __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_comp_topic_rclcpp __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_topic_rclcpp __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_comp_topic_rclcpp __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_CPP_BUILDING_DLL_comp_topic_rclcpp
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_topic_rclcpp
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_comp_topic_rclcpp
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_topic_rclcpp __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_comp_topic_rclcpp
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_topic_rclcpp
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // COMP_TOPIC_RCLCPP__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_
