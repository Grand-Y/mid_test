#include <vector>
#include <onnxruntime/include/onnxruntime_cxx_api.h>
#include <onnxruntime/include/cpu_provider_factory.h>
#include "yolo_detect.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::Bbox;


// NMS
std::vector<int> non_max_suppression(const std::vector<cv::Rect>& boxes, const std::vector<float>& confidences, float iou_threshold) {
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, 0.0, iou_threshold, indices);
    return indices;
}

std::shared_ptr<YoloResult> yolo_detect(cv::Mat &image) {
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "ONNXRuntime");
    auto yolo_result = std::make_shared<YoloResult>();
    // 指定模型路径
    const char* model_path = "/apollo/cyber/a_mid_test/third_party/yolov5s.onnx";

    // 创建 session 选项
    Ort::SessionOptions session_options;
    session_options.SetIntraOpNumThreads(1);
    session_options.SetGraphOptimizationLevel(ORT_ENABLE_BASIC);

    // 创建onnxruntime session
    Ort::Session session(env, model_path, session_options);

    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(640, 640));
    resized_image.convertTo(resized_image, CV_32F, 1.0 / 255.0);
    cv::cvtColor(resized_image, resized_image, cv::COLOR_BGR2RGB);

    // HWC to CHW
    std::vector<float> input_tensor_values;
    for (int c = 0; c < 3; ++c) {
        for (int h = 0; h < 640; ++h) {
            for (int w = 0; w < 640; ++w) {
                input_tensor_values.push_back(resized_image.at<cv::Vec3f>(h, w)[c]);
            }
        }
    }

    // 构建输入张量
    std::vector<int64_t> input_shape = {1, 3, 640, 640};
    Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
    Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(), input_shape.data(), input_shape.size());

    Ort::AllocatorWithDefaultOptions ort_alloc;
    Ort::AllocatedStringPtr inputName = session.GetInputNameAllocated(0, ort_alloc);
    Ort::AllocatedStringPtr outputName = session.GetOutputNameAllocated(0, ort_alloc);
    const std::array<const char*, 1> inputNames = {inputName.get()};
    const std::array<const char*, 1> outputNames = {outputName.get()};


    // 运行模型
    auto output_tensors = session.Run(Ort::RunOptions{nullptr}, inputNames.data(), &input_tensor, 1, outputNames.data(), 1);

    // 处理输出张量
    float* output_data = output_tensors[0].GetTensorMutableData<float>();
    auto output_shape = output_tensors[0].GetTensorTypeAndShapeInfo().GetShape();
    int num_boxes = output_shape[1];

    // YOLOv5 输出格式: [batch, boxes, 85]
    // 每个 box 为 [x_center, y_center, width, height, confidence, class_scores...]
    int image_width = image.cols;
    int image_height = image.rows;
    float scale_x = static_cast<float>(image_width) / 640.0f;
    float scale_y = static_cast<float>(image_height) / 640.0f;

    std::vector<cv::Rect> boxes;
    std::vector<float> confidences;
    std::vector<int> class_ids;

    // 数据保存
    for (int i = 0; i < num_boxes; ++i) {
        float confidence = output_data[i * 85 + 4];
        if (confidence > 0.5) {  // Confidence threshold
            float x_center = output_data[i * 85] * scale_x;
            float y_center = output_data[i * 85 + 1] * scale_y;
            float width = output_data[i * 85 + 2] * scale_x;
            float height = output_data[i * 85 + 3] * scale_y;

            int left = static_cast<int>(x_center - width / 2);
            int top = static_cast<int>(y_center - height / 2);
            int right = static_cast<int>(x_center + width / 2);
            int bottom = static_cast<int>(y_center + height / 2);

            boxes.emplace_back(cv::Rect(left, top, right - left, bottom - top));
            confidences.push_back(confidence);

            // 找到具体的类别
            int max_class_id = 0;
            float max_class_score = output_data[i * 85 + 5]; // Assume class_scores start at index 5
            for (int j = 1; j < 80; ++j) { // Assume there are 80 classes
                float class_score = output_data[i * 85 + 5 + j];
                if (class_score > max_class_score) {
                    max_class_score = class_score;
                    max_class_id = j;
                }
            }
            class_ids.push_back(max_class_id);
        }
    }

    // NMS 去除重复框
    float nms_threshold = 0.5;
    std::vector<int> nms_indices = non_max_suppression(boxes, confidences, nms_threshold);

    for (int idx : nms_indices) {
        cv::Rect box = boxes[idx];
        float confidence = confidences[idx];
        int class_id = class_ids[idx];

        // 识别结果添加到消息中
        auto bbox = yolo_result->add_bboxresult();
        bbox->set_x(box.x);
        bbox->set_y(box.y);
        bbox->set_w(box.width);
        bbox->set_h(box.height);
        bbox->set_prob(confidence);
        bbox->set_obj_id(class_id);
        
        // cv::rectangle(image, box, cv::Scalar(0, 255, 0), 2);
        // std::string label = "Conf: " + std::to_string(confidences[idx]);
        // cv::putText(image, label, cv::Point(box.x, box.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.9, cv::Scalar(0, 255, 0), 2);
    }
    
    // cv::imwrite("/apollo/cyber/a_mid_test/a/result.png", image);

    return yolo_result;
}
