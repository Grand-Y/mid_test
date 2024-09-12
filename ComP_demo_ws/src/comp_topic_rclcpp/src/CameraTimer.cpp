#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class CameraTimer : public rclcpp::Node
{
public:
    CameraTimer(std::string name) : Node(name), current_image_index(0)
    {
        RCLCPP_INFO(this->get_logger(), "%s节点已经启动.", name.c_str());
        cameratimer_topic_publisher = this->create_publisher<sensor_msgs::msg::Image>("CameraTimerImage", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&CameraTimer::timer_callback, this));

        const char *data_path_env = std::getenv("DATA_PATH");
        const char *workspace_env = std::getenv("WORKSPACE");
        
        if (data_path_env == nullptr || workspace_env == nullptr)
        {
            RCLCPP_ERROR(this->get_logger(), "环境变量DATA_PATH或WORKSPACE未设置");
            return;
        }

        // 设置标志路径
        flag_path = std::string(workspace_env) + "/flag";

        // 获取所有图像文件路径
        for (const auto &entry : fs::directory_iterator(data_path_env))
        {
            if (entry.path().extension() == ".jpg")
            {
                image_paths.push_back(entry.path().string());
            }
        }

        // 按文件名排序
        std::sort(image_paths.begin(), image_paths.end());

        if (image_paths.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "未找到任何图像文件.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "已加载 %zu 张图像文件.", image_paths.size());
    }

private:
    void timer_callback()
    {
        // 检查当前图像索引是否超出
        if (current_image_index >= image_paths.size())
        {
            RCLCPP_INFO(this->get_logger(), "图片发布完毕，创建 flag 路径.");

            // 在图片发布完毕时创建标志路径（作为文件夹）
            if (!fs::exists(flag_path))
            {
                fs::create_directory(flag_path);
                RCLCPP_INFO(this->get_logger(), "flag 路径已创建.");
            }

            timer_->cancel(); // 停止定时器
            return;
        }

        // 加载当前图像
        image_ = cv::imread(image_paths[current_image_index]);
        if (image_.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "无法加载图像文件: %s", image_paths[current_image_index].c_str());
            current_image_index++;
            return; // 跳过错误的图像文件
        }

        // 创建ROS图像消息
        sensor_msgs::msg::Image::UniquePtr msg(new sensor_msgs::msg::Image());
        msg->header.stamp = this->now();
        msg->header.frame_id = "camera_frame";

        msg->height = image_.rows;
        msg->width = image_.cols;
        msg->encoding = "bgr8";
        msg->is_bigendian = false;
        msg->step = static_cast<sensor_msgs::msg::Image::_step_type>(image_.step);
        msg->data.assign(image_.datastart, image_.dataend);

        // 打印日志并发布消息
        RCLCPP_INFO(this->get_logger(), "CameraTimer 正在发布图像: %s", image_paths[current_image_index].c_str());
        cameratimer_topic_publisher->publish(std::move(msg));

        // 更新当前图像索引
        current_image_index++;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr cameratimer_topic_publisher;
    cv::Mat image_;
    std::vector<std::string> image_paths;
    size_t current_image_index;
    std::string flag_path;  // 标志路径
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraTimer>("CameraTimer");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
