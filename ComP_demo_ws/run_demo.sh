#!/bin/bash
killall gnome-terminal-server

# Step 1: 编译指定包
colcon build --packages-select comp_topic_rclcpp

# Step 2: 在新终端中运行节点
gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Final; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Lane; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Tracker; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Yolo; exec bash"
gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp CameraTimer; exec bash"

# Step 3: 在新终端中启动 rqt
# export DISPLAY=:0
gnome-terminal -- bash -c "source install/setup.bash; echo $DISPLAY; export DISPLAY=:0; rqt; exec bash"
