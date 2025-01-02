# #!/bin/bash
# killall gnome-terminal-server

# # Step 1: 编译指定包
# colcon build --packages-select comp_topic_rclcpp

# # Step 2: 在新终端中运行节点
# gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Final; exec bash"
# gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Lane; exec bash"
# gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Tracker; exec bash"
# gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp Yolo; exec bash"
# gnome-terminal -- bash -c "source install/setup.bash; ros2 run comp_topic_rclcpp CameraTimer; exec bash"

# # Step 3: 在新终端中启动 rqt
# # export DISPLAY=:0
# gnome-terminal -- bash -c "source install/setup.bash; echo $DISPLAY; export DISPLAY=:0; rqt; exec bash"

#!/bin/bash

# 确保脚本在错误时停止执行
set -e

# 清理函数
cleanup() {
    echo "Cleaning up..."
    # 终止 screen 会话
    screen -S ros2_session -X quit
    echo "Screen session terminated."
    exit 0
}

# 设置信号处理
trap cleanup SIGINT SIGTERM

# 设置ROS 2环境
source /opt/ros/$ROS_DISTRO/setup.bash

# Step 1: 编译指定包
colcon build --packages-select comp_topic_rclcpp

# 设置工作空间
source install/setup.bash

# 确保 screen 已安装
if ! command -v screen &> /dev/null; then
    echo "Screen is not installed. Installing..."
    apt-get update && apt-get install -y screen
fi

# 创建一个新的screen会话
screen -dmS ros2_session

# 在screen会话中启动各个节点
screen -S ros2_session -X screen -t Final bash -c "ros2 run comp_topic_rclcpp Final; exec bash"
screen -S ros2_session -X screen -t Lane bash -c "ros2 run comp_topic_rclcpp Lane; exec bash"
screen -S ros2_session -X screen -t Tracker bash -c "ros2 run comp_topic_rclcpp Tracker; exec bash"
screen -S ros2_session -X screen -t Yolo bash -c "ros2 run comp_topic_rclcpp Yolo; exec bash"
screen -S ros2_session -X screen -t CameraTimer bash -c "ros2 run comp_topic_rclcpp CameraTimer; exec bash"

echo "All nodes have been started in a screen session named 'ros2_session'."
echo "To attach to this session, use: screen -r ros2_session"
echo "To detach from the session, press Ctrl-A followed by D"
echo "This script will keep running. To stop all nodes and clean up, press Ctrl-C"

# 保持脚本运行
while true; do
    sleep 1
done