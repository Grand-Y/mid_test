#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "comp_topic_rclcpp::comp_topic_rclcpp__rosidl_generator_py" for configuration ""
set_property(TARGET comp_topic_rclcpp::comp_topic_rclcpp__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(comp_topic_rclcpp::comp_topic_rclcpp__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcomp_topic_rclcpp__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libcomp_topic_rclcpp__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS comp_topic_rclcpp::comp_topic_rclcpp__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_comp_topic_rclcpp::comp_topic_rclcpp__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libcomp_topic_rclcpp__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)