// #include <opencv2/opencv.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::Mat::zeros(100, 100, CV_8UC3);
    if (image.empty()) {
        std::cout << "Could not create image" << std::endl;
        return -1;
    }
    std::cout << "OpenCV is working" << std::endl;
    return 0;
}