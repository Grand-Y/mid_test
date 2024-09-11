#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// using namespace rclcpp;

class CameraTimer : public rclcpp::Node // 继承方式是public
{
public:
    // 构造函数，一个参数，节点名称
    CameraTimer(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "%s节点已经启动.", name.c_str());
        // 创建话题发布者
        cameratimer_topic_publisher = this->create_publisher<sensor_msgs::msg::Image>("CameraTimerImage", 10);
        // 创建定时器，500ms周期，定时发布
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&CameraTimer::timer_callback, this));
        const char *data_path_env = std::getenv("DATA_PATH");
        if (data_path_env == nullptr){
            RCLCPP_ERROR(this->get_logger(), "环境变量DATA_PATH未设置");        }
        // 加载图像文件
        // 在ROS 2中，使用相对路径加载文件时，路径是相对于节点的工作目录而不是相对于.cpp文件的路径或ROS 2工作空间（ws）的根目录。
        image_ = cv::imread(data_path_env); // 根据路径加载图像
        if (image_.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "无法加载图像文件: %s", data_path_env);
        }
    }

private:
    void timer_callback()
    {
        if (image_.empty())
        {
            return; // 如果图像未成功加载，则不执行发布操作
        }
        // 创建消息
        //  std_msgs::msg::String message;
        //  message.data = "Msg from CameraTimer";
        // 日志打印
        //  RCLCPP_INFO(this->get_logger(),"CameraTimer is Publishing:'%s'",message.data.c_str());
        // 发布消息
        //  cameratimer_topic_publisher->publish(message);

        // 创建ROS图像消息
        sensor_msgs::msg::Image::UniquePtr msg(new sensor_msgs::msg::Image());
        msg->header.stamp = this->now();
        msg->header.frame_id = "camera_frame";

        // 将OpenCV图像数据填充到ROS图像消息中
        msg->height = image_.rows;
        msg->width = image_.cols;
        msg->encoding = "bgr8";
        msg->is_bigendian = false;
        msg->step = static_cast<sensor_msgs::msg::Image::_step_type>(image_.step);
        msg->data.assign(image_.datastart, image_.dataend);

        // 打印日志并发布消息
        RCLCPP_INFO(this->get_logger(), "CameraTimer 正在发布图像");
        cameratimer_topic_publisher->publish(std::move(msg));
    }
    // 声明定时器指针
    rclcpp::TimerBase::SharedPtr timer_;
    // 声明话题发布者
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr cameratimer_topic_publisher;
    // OpenCV图像
    cv::Mat image_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<CameraTimer>("CameraTimer");
    /*运行同时检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}