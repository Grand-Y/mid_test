cmake_minimum_required(VERSION 3.8)
project(comp_topic_rclcpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 包含头文件目录
include_directories(include ${OpenCV_INCLUDE_DIRS} /usr/local/include)

# 生成自定义消息类型
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/YoloPiece.msg"
  "msg/YoloResult.msg"
  "msg/TrackerResult.msg"
  "msg/LaneResult.msg"
  "msg/PointDetect.msg"
  DEPENDENCIES std_msgs
)

# 获取类型支持目标
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

# 可执行文件定义和依赖项
add_executable(CameraTimer src/CameraTimer.cpp)
ament_target_dependencies(CameraTimer rclcpp std_msgs sensor_msgs)
target_link_libraries(CameraTimer ${OpenCV_LIBS})

add_executable(Final src/Final.cpp)
ament_target_dependencies(Final rclcpp std_msgs sensor_msgs)
target_link_libraries(Final ${cpp_typesupport_target} ${OpenCV_LIBS})

add_executable(Tracker src/Tracker.cpp)
ament_target_dependencies(Tracker rclcpp std_msgs sensor_msgs)
target_link_libraries(Tracker ${cpp_typesupport_target} ${OpenCV_LIBS})

add_executable(Lane src/Lane.cpp src/lane_detect.cpp)
ament_target_dependencies(Lane rclcpp std_msgs sensor_msgs)
target_link_libraries(Lane ${cpp_typesupport_target} ${OpenCV_LIBS})

add_executable(Yolo src/Yolo.cpp)
ament_target_dependencies(Yolo rclcpp std_msgs sensor_msgs)
target_link_libraries(Yolo ${cpp_typesupport_target} ${OpenCV_LIBS} onnxruntime)

# 安装目标
install(TARGETS
  CameraTimer
  Final
  Tracker
  Lane
  Yolo
  DESTINATION lib/${PROJECT_NAME}
)

# 测试部分
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
