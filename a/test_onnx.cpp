#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <onnxruntime/include/onnxruntime_cxx_api.h>
#include <onnxruntime/include/cpu_provider_factory.h>

// NMS function
std::vector<int> non_max_suppression(const std::vector<cv::Rect>& boxes, const std::vector<float>& confidences, float iou_threshold) {
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, 0.0, iou_threshold, indices);
    return indices;
}

int main() {
    // Initialize the ONNX Runtime environment
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "ONNXRuntime");

    // Specify the path to the ONNX model
    const char* model_path = "/apollo/cyber/a_mid_test/third_party/yolov5s.onnx";

    // Create session options
    Ort::SessionOptions session_options;
    session_options.SetIntraOpNumThreads(1);
    session_options.SetGraphOptimizationLevel(ORT_ENABLE_BASIC);

    try {
        // Create the ONNX Runtime session
        Ort::Session session(env, model_path, session_options);
        std::cout << "Model loaded successfully!" << std::endl;

        // Load and preprocess the image
        cv::Mat image = cv::imread("/apollo/cyber/a_mid_test/a/image.png");
        if (image.empty()) {
            std::cerr << "Failed to load image." << std::endl;
            return -1;
        }

        cv::Mat resized_image;
        cv::resize(image, resized_image, cv::Size(640, 640));
        resized_image.convertTo(resized_image, CV_32F, 1.0 / 255.0);
        cv::cvtColor(resized_image, resized_image, cv::COLOR_BGR2RGB);
        std::cout << "Get image successfully!" << std::endl;

        // Convert HWC to CHW
        std::vector<float> input_tensor_values;
        for (int c = 0; c < 3; ++c) {
            for (int h = 0; h < 640; ++h) {
                for (int w = 0; w < 640; ++w) {
                    input_tensor_values.push_back(resized_image.at<cv::Vec3f>(h, w)[c]);
                }
            }
        }

        // Create input tensor
        std::vector<int64_t> input_shape = {1, 3, 640, 640};
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(), input_shape.data(), input_shape.size());
        std::cout << "Create input tensor successfully!" << std::endl;

        Ort::AllocatorWithDefaultOptions ort_alloc;
        Ort::AllocatedStringPtr inputName = session.GetInputNameAllocated(0, ort_alloc);
        Ort::AllocatedStringPtr outputName = session.GetOutputNameAllocated(0, ort_alloc);

        const std::array<const char*, 1> inputNames = {inputName.get()};
        const std::array<const char*, 1> outputNames = {outputName.get()};

        for (const auto& name : inputNames) {
            std::cout << "Input name: " << name << std::endl;
        }
        for (const auto& name : outputNames) {
            std::cout << "Output name: " << name << std::endl;
        }

        // Run the model
        auto output_tensors = session.Run(Ort::RunOptions{nullptr}, inputNames.data(), &input_tensor, 1, outputNames.data(), 1);
        std::cout << "Run model successfully!" << std::endl;

        // Process the output tensor
        float* output_data = output_tensors[0].GetTensorMutableData<float>();
        auto output_shape = output_tensors[0].GetTensorTypeAndShapeInfo().GetShape();
        int num_boxes = output_shape[1];
        std::cout << "Number of boxes: " << num_boxes << std::endl;

        // YOLOv5 output format: [batch, boxes, 85]
        // where each box is represented by [x_center, y_center, width, height, confidence, class_scores...]
        int image_width = image.cols;
        int image_height = image.rows;
        float scale_x = static_cast<float>(image_width) / 640.0f;
        float scale_y = static_cast<float>(image_height) / 640.0f;

        std::vector<cv::Rect> boxes;
        std::vector<float> confidences;

        // Draw bounding boxes on the original image
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
            }
        }

        // Apply NMS
        float nms_threshold = 0.5;
        std::vector<int> nms_indices = non_max_suppression(boxes, confidences, nms_threshold);

        for (int idx : nms_indices) {
            cv::Rect box = boxes[idx];
            cv::rectangle(image, box, cv::Scalar(0, 255, 0), 2);
            std::string label = "Conf: " + std::to_string(confidences[idx]);
            cv::putText(image, label, cv::Point(box.x, box.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.9, cv::Scalar(0, 255, 0), 2);
        }

        // Save the result image
        cv::imwrite("/apollo/cyber/a_mid_test/a/result.png", image);

    } catch (const Ort::Exception& e) {
        std::cerr << "Failed to load model: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
