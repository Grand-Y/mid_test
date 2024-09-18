#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "comp_topic_rclcpp/msg/yolo_result.hpp"
#include "comp_topic_rclcpp/msg/tracker_result.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>

class Tracker : public rclcpp::Node
{
public:
    Tracker() : Node("Tracker"), tracking_initialized_(false), yolo_result_received_(false)
    {
        RCLCPP_INFO(this->get_logger(), "Tracker节点已启动.");

        log_path_env = std::getenv("LOG_PATH");
        log_path = std::string(log_path_env);  // 使用从环境变量中获取的路径

        rclcpp::QoS qos_settings(rclcpp::KeepLast(200));  // 设置队列大小为200
        qos_settings.reliable();  // 设置可靠传输

        // 创建订阅者，订阅CameraTimer发布的图像
        image_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "CameraTimerImage", qos_settings, std::bind(&Tracker::image_callback, this, std::placeholders::_1));

        // 创建订阅者，订阅Yolo发布的检测结果
        yolo_result_subscription_ = this->create_subscription<comp_topic_rclcpp::msg::YoloResult>(
            "YoloDetectionResults", qos_settings, std::bind(&Tracker::yolo_result_callback, this, std::placeholders::_1));

        // 创建发布者，用于发布追踪结果
        tracker_result_publisher_ = this->create_publisher<comp_topic_rclcpp::msg::TrackerResult>("TrackerResults", 10);

        // 创建发布者，用于发布原始相机图像
        raw_image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("TrackerRawImage", 10);

        // 初始化日志文件
        initialize_log_file("tra_Tracker_CameraTimerImage");
        initialize_log_file("tra_Tracker_YoloDetectionResults");
        initialize_log_file("cal_Tracker");
    }

private:

    const char* log_path_env;
    std::string log_path;

    // 初始化日志文件
    void initialize_log_file(const std::string &log_name)
    {
        std::string log_file = log_path + "/" + log_name + ".log";
        std::ofstream ofs(log_file, std::ios_base::trunc);  // 清空文件
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
    void log_tra_latency(const std::string &topic_name, const rclcpp::Time &msg_time)
    {
        auto now = this->get_clock()->now();
        auto latency_ns = now.nanoseconds() - msg_time.nanoseconds();
        std::string log_file = log_path + "/tra_Tracker_" + topic_name + ".log";

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
        std::string log_file = log_path + "/cal_Tracker.log";

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

    // 订阅消息回调函数：处理图像消息并记录延迟
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Tracker订阅收到 CameraTimer 发布的图像");

        // 记录消息传输延迟
        log_tra_latency("CameraTimerImage", msg->header.stamp);

        // 开始计时计算延迟
        auto start_time = this->get_clock()->now().nanoseconds();

        // 将ROS图像消息转换为OpenCV格式的图像，并赋值给类成员frame_
        frame_ = cv::Mat(msg->height, msg->width, CV_8UC3, const_cast<unsigned char *>(msg->data.data()), msg->step);
        latest_image_msg_ = msg; // 保存最新的图像消息

        if (!yolo_result_received_)
        {
            RCLCPP_INFO(this->get_logger(), "等待Yolo结果，暂停追踪");
            return;
        }

        bool tracking_success = false; // 用于跟踪是否成功追踪目标

        if (tracking_initialized_)
        {
            // 追踪现有的目标
            for (size_t i = 0; i < trackers_.size(); ++i)
            {
                cv::Rect bbox;
                bool ok = trackers_[i]->update(frame_, bbox);
                if (ok)
                {
                    cv::rectangle(frame_, bbox, cv::Scalar(255, 0, 0), 2, 1);

                    // 创建TrackerResult消息并发布
                    auto tracker_result_msg = comp_topic_rclcpp::msg::TrackerResult();
                    tracker_result_msg.header.stamp = this->now();
                    tracker_result_msg.x = bbox.x;
                    tracker_result_msg.y = bbox.y;
                    tracker_result_msg.width = bbox.width;
                    tracker_result_msg.height = bbox.height;

                    tracker_result_publisher_->publish(tracker_result_msg);
                    tracking_success = true; // 成功追踪
                }
            }
        }

        // 如果没有成功追踪到任何目标，发布原始图像
        if (!tracking_success)
        {
            RCLCPP_WARN(this->get_logger(), "没有成功追踪目标，发布原始相机图像");
            raw_image_publisher_->publish(*latest_image_msg_); // 发布最新的原始图像
        }

        // 结束计时并记录计算延迟
        auto end_time = this->get_clock()->now().nanoseconds();
        log_cal_latency(end_time - start_time);

        // 显示当前追踪状态
        cv::imshow("Tracking", frame_);
        cv::waitKey(1);
    }

    // 处理Yolo结果并初始化追踪器
    void yolo_result_callback(const comp_topic_rclcpp::msg::YoloResult::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Tracker订阅收到 Yolo 发布的检测结果");

        // 记录消息传输延迟
        log_tra_latency("YoloDetectionResults", msg->header.stamp);

        // 检查图像是否已经初始化
        if (frame_.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "当前没有有效的图像来初始化追踪器.");
            return;
        }

        trackers_.clear(); // 清空之前的追踪器
        for (const auto &yolo_piece : msg->result_array)
        {
            // 计算左上角坐标
            double x_left = yolo_piece.x;
            double y_top = yolo_piece.y;
            double width = yolo_piece.w;
            double height = yolo_piece.h;

            // 检查边界框是否有效
            if (width <= 0 || height <= 0)
            {
                RCLCPP_WARN(this->get_logger(), "无效的边界框，跳过该检测结果: x_left = %.2f, y_top = %.2f, width = %.2f, height = %.2f", x_left, y_top, width, height);
                continue;
            }

            cv::Rect bbox(cv::Point(x_left, y_top), cv::Size(width, height));

            RCLCPP_INFO(this->get_logger(), "有效的边界框: x_left = %.2f, y_top = %.2f, width = %.2f, height = %.2f", x_left, y_top, width, height);

            // 初始化追踪器，捕获异常
            try
            {
                auto tracker = cv::TrackerKCF::create(); // 使用 cv::TrackerKCF
                tracker->init(frame_, bbox);             // 初始化追踪器
                trackers_.push_back(tracker);
            }
            catch (const cv::Exception &e)
            {
                RCLCPP_ERROR(this->get_logger(), "追踪器初始化失败: %s", e.what());
                continue;
            }
        }

        tracking_initialized_ = true;
        yolo_result_received_ = true; // 标记Yolo结果已收到
    }

    // 订阅者和发布者
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
    rclcpp::Subscription<comp_topic_rclcpp::msg::YoloResult>::SharedPtr yolo_result_subscription_;
    rclcpp::Publisher<comp_topic_rclcpp::msg::TrackerResult>::SharedPtr tracker_result_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr raw_image_publisher_;  // 用于发布原始图像

    // 追踪器相关
    std::vector<cv::Ptr<cv::Tracker>> trackers_;
    bool tracking_initialized_;
    bool yolo_result_received_; // 标记是否收到Yolo检测结果
    cv::Mat frame_;  // 用于保存当前帧图像
    sensor_msgs::msg::Image::SharedPtr latest_image_msg_; // 保存最新的图像消息
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Tracker>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
