cmake_minimum_required(VERSION 3.8)
project(base_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/StrMsg.msg"
  DEPENDENCIES std_msgs
)

include_directories(
  include
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
  ${CMAKE_CURRENT_BINARY_DIR}/include
  ${ament_cmake_INCLUDE_DIRS}
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(PubNode src/b1_1/PubNode.cpp)
ament_target_dependencies(PubNode rclcpp std_msgs rosidl_default_runtime)

add_executable(SubNode src/b1_1/SubNode.cpp) 
ament_target_dependencies(SubNode rclcpp std_msgs rosidl_default_runtime)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(PubNode "${cpp_typesupport_target}")
target_link_libraries(SubNode "${cpp_typesupport_target}")

ament_export_dependencies(rosidl_default_runtime)

install(TARGETS
  PubNode
  SubNode
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
