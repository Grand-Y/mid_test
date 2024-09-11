#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "comp_topic_rclcpp/msg/lane_result.hpp"
#include "comp_topic_rclcpp/lane_detect.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>

class Lane : public rclcpp::Node
{
public:
    Lane(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "%s节点已经启动.", name.c_str());

        // 创建发布者，用于发布检测后的车道线信息
        lane_result_publisher_ = this->create_publisher<comp_topic_rclcpp::msg::LaneResult>("LaneDetectionResults", 10);

        // 创建订阅者，订阅CameraTimer发布的图像
        cameratimer_topic_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "CameraTimerImage", 10, std::bind(&Lane::cameratimer_topic_callback, this, std::placeholders::_1));

        // 初始化日志文件，覆盖旧日志文件
        initialize_log_file("tra_Lane_CameraTimerImage");
        initialize_log_file("cal_Lane");
    }

private:
    
    // 初始化日志文件
    void initialize_log_file(const std::string &log_name)
    {
        const char* log_path_env = std::getenv("LOG_PATH");
        std::string log_path(log_path_env);
        std::string log_file = log_path + "/" + log_name + ".log";
        // std::cout << log_file << std::endl;
        std::ofstream ofs(log_file, std::ios_base::trunc);  // 覆盖旧文件
        if (ofs.is_open())
        {
            // ofs << "Log initialized for: " << log_name << std::endl;
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法初始化日志文件: %s", log_file.c_str());
        }
    }

    // 记录传输延迟到日志文件
    void log_tra_latency(const rclcpp::Time &msg_time)
    {
        const char* log_path_env = std::getenv("LOG_PATH");
        std::string log_path(log_path_env);
        auto now = this->get_clock()->now();
        auto latency_ns = now.nanoseconds() - msg_time.nanoseconds();
        std::string log_file = log_path + "/tra_Lane_CameraTimerImage.log";

        // 追加写入传输延迟日志
        std::ofstream ofs(log_file, std::ios_base::app);
        if (ofs.is_open())
        {
            ofs << latency_ns / 1e3 << std::endl;  // 以微秒为单位记录
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法打开传输延迟日志文件: %s", log_file.c_str());
        }
    }

    // 记录计算延迟到日志文件
    void log_cal_latency(const uint64_t &latency_ns)
    {
        const char* log_path_env = std::getenv("LOG_PATH");
        std::string log_path(log_path_env);
        std::string log_file = log_path + "/cal_Lane.log";

        // 追加写入计算延迟日志
        std::ofstream ofs(log_file, std::ios_base::app);
        if (ofs.is_open())
        {
            ofs << latency_ns / 1e3 << std::endl;  // 以微秒为单位记录
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法打开计算延迟日志文件: %s", log_file.c_str());
        }
    }

    // 订阅消息回调函数：处理传入的图像并记录延迟
    void cameratimer_topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Lane订阅收到CameraTimer发布的图像");

        // 记录消息传输延迟
        log_tra_latency(msg->header.stamp);

        // 开始计时计算延迟
        auto start_time = this->get_clock()->now().nanoseconds();

        // 将ROS图像消息转换为OpenCV格式的图像
        cv::Mat frame(msg->height, msg->width, CV_8UC3, const_cast<unsigned char *>(msg->data.data()), msg->step);

        // 处理车道线，假设lane_process函数返回4个点
        cv::Point result[4];
        lane_process(frame, result);

        // 创建LaneResult消息
        auto lane_result_msg = comp_topic_rclcpp::msg::LaneResult();
        lane_result_msg.header.stamp = this->now();

        // 填充LaneResult消息中的每个点
        lane_result_msg.left1.x = result[0].x;
        lane_result_msg.left1.y = result[0].y;
        lane_result_msg.right1.x = result[1].x;
        lane_result_msg.right1.y = result[1].y;
        lane_result_msg.left2.x = result[2].x;
        lane_result_msg.left2.y = result[2].y;
        lane_result_msg.right2.x = result[3].x;
        lane_result_msg.right2.y = result[3].y;

        // 发布LaneResult消息
        lane_result_publisher_->publish(lane_result_msg);

        RCLCPP_INFO(this->get_logger(), "发布检测到的车道线结果.");

        // 结束计时并记录计算延迟
        auto end_time = this->get_clock()->now().nanoseconds();
        log_cal_latency(end_time - start_time);
    }

    // 声明发布者
    rclcpp::Publisher<comp_topic_rclcpp::msg::LaneResult>::SharedPtr lane_result_publisher_;
    // 声明订阅者
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr cameratimer_topic_subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Lane>("Lane");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
