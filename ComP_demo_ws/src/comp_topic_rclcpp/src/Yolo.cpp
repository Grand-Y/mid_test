#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include <onnxruntime/onnxruntime_cxx_api.h>
#include "comp_topic_rclcpp/msg/yolo_piece.hpp"
#include "comp_topic_rclcpp/msg/yolo_result.hpp"
#include <fstream>

class Yolo : public rclcpp::Node
{
public:
    Yolo(std::string name) : Node(name), env(ORT_LOGGING_LEVEL_WARNING, "YOLOv5")
    {
        RCLCPP_INFO(this->get_logger(), "%s 节点已启动.", name.c_str());

        log_path_env = std::getenv("LOG_PATH");
        model_path_env = std::getenv("MODEL_PATH");
        log_path = std::string(log_path_env);  // 使用从环境变量中获取的路径

        rclcpp::QoS qos_settings(rclcpp::KeepLast(200));  // 设置队列大小为200
        qos_settings.reliable();  // 设置可靠传输

        // 创建图像发布者，用于发布处理后的图像
        yolo_image_publisher = this->create_publisher<sensor_msgs::msg::Image>("YoloProcessedImage", 10);

        // 创建YOLO检测结果的发布者
        yolo_result_publisher = this->create_publisher<comp_topic_rclcpp::msg::YoloResult>("YoloDetectionResults", 10);

        // 创建订阅CameraTimer发布的图像消息的订阅者
        cameratimer_topic_subscription = this->create_subscription<sensor_msgs::msg::Image>(
            "CameraTimerImage", qos_settings, std::bind(&Yolo::cameratimer_topic_callback, this, std::placeholders::_1));

        // 初始化日志文件
        initialize_log_file("tra_Yolo_CameraTimerImage");
        initialize_log_file("cal_Yolo");

        // 指定YOLO模型路径
        const char *model_path = model_path_env;
        Ort::SessionOptions session_options;
        session_options.SetIntraOpNumThreads(1);
        session_options.SetGraphOptimizationLevel(ORT_ENABLE_BASIC);
        session = std::make_shared<Ort::Session>(env, model_path, session_options);
    }

private:
    const char *log_path_env;
    const char *model_path_env;
    std::string log_path;

    // 初始化日志文件
    void initialize_log_file(const std::string &log_name)
    {
        std::string log_file = log_path + "/" + log_name + ".log";
        std::ofstream ofs(log_file, std::ios_base::trunc); // 清空文件
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
        auto now = this->get_clock()->now();
        auto latency_ns = now.nanoseconds() - msg_time.nanoseconds();
        std::string log_file = log_path + "/tra_Yolo_CameraTimerImage.log";

        // 追加写入传输延迟日志
        std::ofstream ofs(log_file, std::ios_base::app);
        if (ofs.is_open())
        {
            ofs << latency_ns / 1e3 << std::endl; // 以微秒为单位记录
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
        std::string log_file = log_path + "/cal_Yolo.log";

        // 追加写入计算延迟日志
        std::ofstream ofs(log_file, std::ios_base::app);
        if (ofs.is_open())
        {
            ofs << latency_ns / 1e3 << std::endl; // 以微秒为单位记录
            ofs.close();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "无法打开计算延迟日志文件: %s", log_file.c_str());
        }
    }

    // 订阅消息回调函数：处理图像消息并记录延迟
    void cameratimer_topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        
        RCLCPP_INFO(this->get_logger(), "Yolo订阅收到 CameraTimer 发布的图像");

        // 记录消息传输延迟
        log_tra_latency(msg->header.stamp);

        // 开始计时计算延迟
        auto start_time = this->get_clock()->now().nanoseconds();

        // 将ROS图像消息转换为OpenCV格式的图像
        cv::Mat frame(msg->height, msg->width, CV_8UC3, const_cast<unsigned char *>(msg->data.data()), msg->step);

        // YOLOv5模型输入尺寸
        cv::Mat resized_image;
        cv::resize(frame, resized_image, cv::Size(640, 640));
        resized_image.convertTo(resized_image, CV_32F, 1.0 / 255.0);
        cv::cvtColor(resized_image, resized_image, cv::COLOR_BGR2RGB);

        // HWC to CHW
        std::vector<float> input_tensor_values;
        for (int c = 0; c < 3; ++c)
        {
            for (int h = 0; h < 640; ++h)
            {
                for (int w = 0; w < 640; ++w)
                {
                    input_tensor_values.push_back(resized_image.at<cv::Vec3f>(h, w)[c]);
                }
            }
        }

        // 构建输入张量
        std::vector<int64_t> input_shape = {1, 3, 640, 640};
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(), input_shape.data(), input_shape.size());

        Ort::AllocatorWithDefaultOptions ort_alloc;
        Ort::AllocatedStringPtr inputName = session->GetInputNameAllocated(0, ort_alloc);
        Ort::AllocatedStringPtr outputName = session->GetOutputNameAllocated(0, ort_alloc);
        const std::array<const char *, 1> inputNames = {inputName.get()};
        const std::array<const char *, 1> outputNames = {outputName.get()};

        // 运行YOLOv5模型
        auto output_tensors = session->Run(Ort::RunOptions{nullptr}, inputNames.data(), &input_tensor, 1, outputNames.data(), 1);

        // 处理YOLOv5的输出
        float *output_data = output_tensors[0].GetTensorMutableData<float>();
        auto output_shape = output_tensors[0].GetTensorTypeAndShapeInfo().GetShape();
        int num_boxes = output_shape[1];

        int image_width = frame.cols;
        int image_height = frame.rows;
        float scale_x = static_cast<float>(image_width) / 640.0f;
        float scale_y = static_cast<float>(image_height) / 640.0f;

        std::vector<cv::Rect> boxes;
        std::vector<float> confidences;
        std::vector<int> class_ids;

        for (int i = 0; i < num_boxes; ++i)
        {
            float confidence = output_data[i * 85 + 4];
            if (confidence > 0.5)
            {
                float x_center = output_data[i * 85] * scale_x;
                float y_center = output_data[i * 85 + 1] * scale_y;
                float width = output_data[i * 85 + 2] * scale_x;
                float height = output_data[i * 85 + 3] * scale_y;

                int left = static_cast<int>(x_center - width / 2);
                int top = static_cast<int>(y_center - height / 2);
                boxes.emplace_back(cv::Rect(left, top, static_cast<int>(width), static_cast<int>(height)));
                confidences.push_back(confidence);

                int max_class_id = 0;
                float max_class_score = output_data[i * 85 + 5];
                for (int j = 1; j < 80; ++j)
                {
                    float class_score = output_data[i * 85 + 5 + j];
                    if (class_score > max_class_score)
                    {
                        max_class_score = class_score;
                        max_class_id = j;
                    }
                }
                class_ids.push_back(max_class_id);
            }
        }

        // 非极大值抑制
        float nms_threshold = 0.5;
        std::vector<int> nms_indices;
        cv::dnn::NMSBoxes(boxes, confidences, 0.5, nms_threshold, nms_indices);

        // 初始化YoloResult消息
        auto yolo_result_msg = comp_topic_rclcpp::msg::YoloResult();
        yolo_result_msg.header.stamp = this->now();
        yolo_result_msg.header.frame_id = "yolo_frame";
        yolo_result_msg.result_num = 0;

        // 只处理通过NMS的检测结果
        for (int idx : nms_indices)
        {
            const auto &box = boxes[idx];
            float confidence = confidences[idx];
            int class_id = class_ids[idx];

            // 构建YoloPiece消息
            comp_topic_rclcpp::msg::YoloPiece yolo_piece_msg;
            yolo_piece_msg.x = box.x;
            yolo_piece_msg.y = box.y;
            yolo_piece_msg.w = box.width;
            yolo_piece_msg.h = box.height;
            yolo_piece_msg.prob = confidence;
            yolo_piece_msg.obj_id = class_id;

            // 将检测结果添加到YoloResult
            yolo_result_msg.result_array.push_back(yolo_piece_msg);
            yolo_result_msg.result_num++;
        }

        // 发布检测结果
        yolo_result_publisher->publish(yolo_result_msg);
        RCLCPP_INFO(this->get_logger(), "Yolo发布检测结果消息");

        // 结束计时并记录计算延迟
        auto end_time = this->get_clock()->now().nanoseconds();
        log_cal_latency(end_time - start_time);
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr yolo_image_publisher;
    rclcpp::Publisher<comp_topic_rclcpp::msg::YoloResult>::SharedPtr yolo_result_publisher;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr cameratimer_topic_subscription;

    Ort::Env env;
    std::shared_ptr<Ort::Session> session;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Yolo>("Yolo");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
