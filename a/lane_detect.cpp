#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>



struct Point {
    uint32_t x;
    uint32_t y;
};

void fit_lanes(cv::Mat &image, Point* result) {
    int height = image.rows;
    int width = image.cols;

    int cx = width / 2;
    int cy = height / 2;

    std::vector<Point> left_pts;
    std::vector<Point> right_pts;
    cv::Vec4f left;

    for (int i = 100; i < (cx - 10); i++) {
        for (int j = cy; j < height; j++) {
            int pv = image.at<uchar>(j, i);
            if (pv == 255) {
                left_pts.push_back(Point{static_cast<uint32_t>(i), static_cast<uint32_t>(j)});
            }
        }
    }

    for (int i = cx; i < (width - 20); i++) {
        for (int j = cy; j < height; j++) {
            int pv = image.at<uchar>(j, i);
            if (pv == 255) {
                right_pts.push_back(Point{static_cast<uint32_t>(i), static_cast<uint32_t>(j)});
            }
        }
    }

    if (left_pts.size() > 2) {
        std::vector<cv::Point> left_pts_cv;
        for (const auto& pt : left_pts) {
            left_pts_cv.push_back(cv::Point(pt.x, pt.y));
        }
        cv::fitLine(left_pts_cv, left, cv::DIST_L1, 0, 0.01, 0.01);

        double k1 = left[1] / left[0];
        double step = left[3] - k1 * left[2];

        int x1 = int((height - step) / k1);
        int y2 = int((cx - 25) * k1 + step);

        result[0] = {static_cast<uint32_t>(x1), static_cast<uint32_t>(height)};
        result[1] = {static_cast<uint32_t>(cx - 25), static_cast<uint32_t>(y2)};
    }

    if (right_pts.size() > 2) {
        std::vector<cv::Point> right_pts_cv;
        for (const auto& pt : right_pts) {
            right_pts_cv.push_back(cv::Point(pt.x, pt.y));
        }
        cv::fitLine(right_pts_cv, left, cv::DIST_L1, 0, 0.01, 0.01);

        double k1 = left[1] / left[0];
        double step = left[3] - k1 * left[2];

        int x1 = int((height - step) / k1);
        int y2 = int((cx - 25) * k1 + step);

        result[2] = {static_cast<uint32_t>(x1), static_cast<uint32_t>(height)};
        result[3] = {static_cast<uint32_t>(cx - 25), static_cast<uint32_t>(y2)};
    }
}

void lane_process(cv::Mat &frame, Point* result) {
    cv::Mat gray, binary;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, binary, 150, 300);

    for (size_t i = 0; i < (gray.rows / 2 + 40); i++) {
        for (size_t j = 0; j < gray.cols; j++) {
            binary.at<uchar>(i, j) = 0;
        }
    }

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat out_image = cv::Mat::zeros(gray.size(), gray.type());

    for (size_t i = 0; i < contours.size(); i++) {
        double length = cv::arcLength(contours[i], true);
        double area = cv::contourArea(contours[i]);

        if (length < 5.0 || area < 10.0) {
            continue;
        }

        cv::Rect rect = cv::boundingRect(contours[i]);
        int h = gray.rows - 50;

        if (rect.y > h) {
            continue;
        }

        cv::RotatedRect rrt = cv::minAreaRect(contours[i]);
        double angle = std::abs(rrt.angle);

        if (angle < 20.0 || angle > 84.0) {
            continue;
        }

        if (contours[i].size() > 5) {
            cv::RotatedRect errt = cv::fitEllipse(contours[i]);

            if ((errt.angle < 5.0) || (errt.angle > 160.0)) {
                if (80.0 < errt.angle && errt.angle < 100.0) {
                    continue;
                }
            }
        }

        cv::drawContours(out_image, contours, static_cast<int>(i), cv::Scalar(255), 2, 8);
    }

    fit_lanes(out_image, result);
}

int main() {
    // 读取图像
    cv::Mat frame = cv::imread("/apollo/cyber/a_mid_test/data/camera/800-1/front/002758.png");
    if (frame.empty()) {
        std::cerr << "Error: Could not load image!" << std::endl;
        return -1;
    }

    // 定义结果数组
    Point result[4];

    // 处理图像
    lane_process(frame, result);

    // 绘制车道线
    cv::line(frame, cv::Point(result[0].x, result[0].y), cv::Point(result[1].x, result[1].y), cv::Scalar(0, 0, 255), 2);
    cv::line(frame, cv::Point(result[2].x, result[2].y), cv::Point(result[3].x, result[3].y), cv::Scalar(0, 0, 255), 2);

    // 保存结果图像
    cv::imwrite("lane_detection_result.jpg", frame);
    std::cout << "Saved the result image as lane_detection_result.jpg" << std::endl;

    return 0;
}
