#include "rclcpp/rclcpp.hpp"
#include "comp_topic_rclcpp/msg/lane_result.hpp"
#include "comp_topic_rclcpp/msg/yolo_result.hpp"
#include "comp_topic_rclcpp/msg/tracker_result.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>

class Final : public rclcpp::Node
{
public:
    Final() : Node("Final")
    {
        RCLCPP_INFO(this->get_logger(), "Final节点已启动.");

        // 初始化日志文件，覆盖旧数据
        initialize_log_file("LaneDetectionResults");
        initialize_log_file("YoloDetectionResults");
        initialize_log_file("TrackerResults");

        rclcpp::QoS qos_settings(rclcpp::KeepLast(200));  // 设置队列大小为200
        qos_settings.reliable();  // 设置可靠传输

        // 创建订阅者，订阅Lane节点发布的车道线检测结果
        lane_result_subscription_ = this->create_subscription<comp_topic_rclcpp::msg::LaneResult>(
            "LaneDetectionResults", qos_settings, std::bind(&Final::lane_result_callback, this, std::placeholders::_1));

        // 创建订阅者，订阅Yolo节点发布的检测结果
        yolo_result_subscription_ = this->create_subscription<comp_topic_rclcpp::msg::YoloResult>(
            "YoloDetectionResults", qos_settings, std::bind(&Final::yolo_result_callback, this, std::placeholders::_1));

        // 创建订阅者，订阅Tracker节点发布的追踪结果
        tracker_result_subscription_ = this->create_subscription<comp_topic_rclcpp::msg::TrackerResult>(
            "TrackerResults", qos_settings, std::bind(&Final::tracker_result_callback, this, std::placeholders::_1));
    }

private:
    // 初始化日志文件：在节点启动时覆盖旧日志文件
    void initialize_log_file(const std::string &topic_name)
    {
        const char* log_path_env = std::getenv("LOG_PATH");
        std::string log_path(log_path_env);
        std::string log_file = log_path + "/tra_Final_" + topic_name + ".log";

        // 以覆盖模式清空日志文件
        std::ofstream ofs(log_file, std::ios_base::trunc);
        if (ofs.is_open())
        {
            // ofs << "Log initialized for topic: " << topic_name << std::endl;
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法打开日志文件: %s", log_file.c_str());
        }
    }

    // 通用函数：记录传输延迟到日志
    void log_tra_latency(const std::string &topic_name, const rclcpp::Time &msg_time)
    {
        auto now = this->get_clock()->now();
        auto latency_ns = now.nanoseconds() - msg_time.nanoseconds();  // 计算延迟时间（纳秒）
        const char* log_path_env = std::getenv("LOG_PATH");
        // if (log_path_env == nullptr){
        //     RCLCPP_ERROR(this->get_logger(), "环境变量LOG_PATH未设置"); 
        //     return;       }
        // }
        std::string log_path(log_path_env);
        std::string log_file = log_path + "/tra_Final_" + topic_name + ".log";

        // 以追加模式写入日志文件
        std::ofstream ofs(log_file, std::ios_base::app);
        if (ofs.is_open())
        {
            ofs << latency_ns / 1e3 << std::endl;  // 记录以微秒为单位的延迟
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法打开日志文件: %s", log_file.c_str());
        }
    }

    // 回调函数：处理Lane节点发布的车道线检测结果
    void lane_result_callback(const comp_topic_rclcpp::msg::LaneResult::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Final节点订阅到 Lane 的车道线检测结果");
        
        // 记录传输延迟
        log_tra_latency("LaneDetectionResults", msg->header.stamp);

        // 打印每个点的信息
        RCLCPP_INFO(this->get_logger(), "Left1: (%d, %d), Right1: (%d, %d)", 
                    msg->left1.x, msg->left1.y, msg->right1.x, msg->right1.y);
        RCLCPP_INFO(this->get_logger(), "Left2: (%d, %d), Right2: (%d, %d)", 
                    msg->left2.x, msg->left2.y, msg->right2.x, msg->right2.y);
    }

    // 回调函数：处理Yolo节点发布的检测结果
    void yolo_result_callback(const comp_topic_rclcpp::msg::YoloResult::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Final节点订阅到 Yolo 的检测结果");

        // 记录传输延迟
        log_tra_latency("YoloDetectionResults", msg->header.stamp);

        for (const auto &yolo_piece : msg->result_array)
        {
            RCLCPP_INFO(this->get_logger(), "Yolo检测到的边界框: x = %.2f, y = %.2f, width = %.2f, height = %.2f", 
                        yolo_piece.x, yolo_piece.y, yolo_piece.w, yolo_piece.h);
        }
    }

    // 回调函数：处理Tracker节点发布的追踪结果
    void tracker_result_callback(const comp_topic_rclcpp::msg::TrackerResult::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Final节点订阅到 Tracker 的追踪结果: x = %.2f, y = %.2f, width = %.2f, height = %.2f",
                    msg->x, msg->y, msg->width, msg->height);

        // 记录传输延迟
        log_tra_latency("TrackerResults", msg->header.stamp);
    }

    // 订阅者
    rclcpp::Subscription<comp_topic_rclcpp::msg::LaneResult>::SharedPtr lane_result_subscription_;
    rclcpp::Subscription<comp_topic_rclcpp::msg::YoloResult>::SharedPtr yolo_result_subscription_;
    rclcpp::Subscription<comp_topic_rclcpp::msg::TrackerResult>::SharedPtr tracker_result_subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Final>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
