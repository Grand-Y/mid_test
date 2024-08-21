#include <torch/script.h>
#include <torch/torch.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

// Function to resize and pad the image (letterbox)
cv::Mat letterbox(const cv::Mat& src, int new_width, int new_height, float& scale, int& top, int& left) {
    int width = src.cols;
    int height = src.rows;
    float r = std::min(new_width / (float)width, new_height / (float)height);
    int new_unpad_width = static_cast<int>(r * width);
    int new_unpad_height = static_cast<int>(r * height);
    scale = r;
    cv::Mat resized;
    cv::resize(src, resized, cv::Size(new_unpad_width, new_unpad_height), cv::INTER_LINEAR);
    cv::Mat padded = cv::Mat::zeros(new_height, new_width, CV_8UC3);
    top = (new_height - new_unpad_height) / 2;
    left = (new_width - new_unpad_width) / 2;
    resized.copyTo(padded(cv::Rect(left, top, resized.cols, resized.rows)));
    return padded;
}

// Manually implement NMS (Non-Maximum Suppression)
std::vector<int> non_max_suppression(const std::vector<cv::Rect>& boxes, const std::vector<float>& scores, float iou_threshold) {
    std::vector<int> indices;
    if (boxes.empty()) return indices;

    // Sort indices by scores in descending order
    std::vector<int> idxs(boxes.size());
    std::iota(idxs.begin(), idxs.end(), 0);
    std::sort(idxs.begin(), idxs.end(), [&scores](int i1, int i2) { return scores[i1] > scores[i2]; });

    while (!idxs.empty()) {
        int current = idxs[0];
        indices.push_back(current);
        std::vector<int> temp;
        for (int i = 1; i < idxs.size(); ++i) {
            int idx = idxs[i];
            float iou = (boxes[current] & boxes[idx]).area() / float((boxes[current] | boxes[idx]).area());
            if (iou <= iou_threshold) {
                temp.push_back(idx);
            }
        }
        idxs.swap(temp);
    }

    return indices;
}

int main() {
    // Load the TorchScript model
    std::shared_ptr<torch::jit::script::Module> module;
    try {
        module = std::make_shared<torch::jit::script::Module>(torch::jit::load("/apollo/cyber/a_mid_test/3rd_algs/yolov5s.torchscript"));
    }
    catch (const c10::Error &e) {
        std::cerr << "Error loading the model: " << e.what() << "\n";
        return -1;
    }

    // Read the image
    cv::Mat image = cv::imread("/apollo/cyber/a_mid_test/a/image.png");
    if (image.empty()) {
        std::cerr << "Could not read the image\n";
        return -1;
    }

    // Store the original image
    cv::Mat orig_image = image.clone();

    // Preprocess the image
    float scale;
    int top, left;
    cv::Mat padded_image = letterbox(image, 640, 640, scale, top, left);
    padded_image.convertTo(padded_image, CV_32F, 1.0 / 255);

    // Convert image to Torch tensor
    at::Tensor img_tensor = torch::from_blob(padded_image.data, {1, padded_image.rows, padded_image.cols, 3}).permute({0, 3, 1, 2}).contiguous();

    // Perform inference
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(img_tensor);
    at::Tensor output;
    try {
        auto outputs = module->forward(inputs).toTuple();
        output = outputs->elements()[0].toTensor();
    }
    catch (const c10::Error &e) {
        std::cerr << "Error during inference: " << e.what() << "\n";
        return -1;
    }

    // Post-process the output
    auto result = output.squeeze(0).detach().cpu();
    auto detections = result.accessor<float, 2>();

    std::vector<cv::Rect> boxes;
    std::vector<float> scores;
    for (int i = 0; i < detections.size(0); ++i) {
        float x1 = std::max((detections[i][0] - left) / scale, 0.0f);
        float y1 = std::max((detections[i][1] - top) / scale, 0.0f);
        float x2 = std::min((detections[i][2] - left) / scale, static_cast<float>(image.cols));
        float y2 = std::min((detections[i][3] - top) / scale, static_cast<float>(image.rows));
        float conf = detections[i][4];
        if (conf > 0.25) { // Use confidence threshold from detect.py
            boxes.emplace_back(cv::Rect(cv::Point(x1, y1), cv::Point(x2, y2)));
            scores.push_back(conf);
        }
    }

    // Apply non-maximum suppression
    std::vector<int> nms_indices = non_max_suppression(boxes, scores, 0.45);
    std::vector<cv::Rect> nms_boxes;
    for (int idx : nms_indices) {
        nms_boxes.push_back(boxes[idx]);
    }

    // Draw the bounding boxes on the original image
    for (const auto& box : nms_boxes) {
        cv::rectangle(image, box, cv::Scalar(0, 255, 0), 2);
    }

    // Save the result image
    cv::imwrite("/apollo/cyber/a_mid_test/a/result.png", image);
    std::cout << "Inference complete, result saved to /apollo/cyber/a_mid_test/a/result.png\n";

    return 0;
}
