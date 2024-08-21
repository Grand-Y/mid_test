#include <vector>
#include "lane_detect.h"


void file_lanes(Mat &image, Point* result) {
    int height = image.rows;
    int width = image.cols;

    int cx = width / 2;
    int cy = height / 2;

    std::vector<Point> left_pts;
    std::vector<Point> right_pts;
    Vec4f left;

    for (int i = 100; i < (cx - 10); i++) {
        for (int j = cy; j < height; j++) {
            int pv = image.at<uchar>(j, i);
            if (pv == 255) {
                left_pts.push_back(Point(i, j));
            }
        }
    }

    for (int i = cx; i < (width - 20); i++) {
        for (int j = cy; j < height; j++) {
            int pv = image.at<uchar>(j, i);
            if (pv == 255) {
                right_pts.push_back(Point(i, j));
            }
        }
    }

    if (left_pts.size() > 2) {
        fitLine(left_pts, left, DIST_L1, 0, 0.01, 0.01);

        double k1 = left[1] / left[0];
        double step = left[3] - k1 * left[2];

        int x1 = int((height - step) / k1);
        int y2 = int((cx - 25) * k1 + step);

        Point left_spot_1 = Point(x1, height);
        Point left_spot_end = Point((cx - 25), y2);

        result[0] = left_spot_1;
        result[1] = left_spot_end;
    }

    if (right_pts.size() > 2) {
        Point spot_1 = right_pts[0];
        Point spot_end = right_pts[right_pts.size() - 1];

        result[2] = spot_1;
        result[3] = spot_end;
    }
}

void lane_process(Mat &frame, Point* result) {
    Mat gray, binary;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    Canny(gray, binary, 150, 300);

    for (int i = 0; i < (gray.rows / 2 + 40); i++) {
        for (int j = 0; j < gray.cols; j++) {
            binary.at<uchar>(i, j) = 0;
        }
    }

    std::vector<std::vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat out_image = Mat::zeros(gray.size(), gray.type());

    for (size_t i = 0; i < contours.size(); i++) {
        double length = arcLength(contours[i], true);
        double area = contourArea(contours[i]);

        if (length < 5.0 || area < 10.0) {
            continue;
        }

        Rect rect = boundingRect(contours[i]);
        int h = gray.rows - 50;

        if (rect.y > h) {
            continue;
        }

        RotatedRect rrt = minAreaRect(contours[i]);
        double angle = std::abs(rrt.angle);

        if (angle < 20.0 || angle > 84.0) {
            continue;
        }

        if (contours[i].size() > 5) {
            RotatedRect errt = fitEllipse(contours[i]);

            if ((errt.angle < 5.0) || (errt.angle > 160.0)) {
                if (80.0 < errt.angle && errt.angle < 100.0) {
                    continue;
                }
            }
        }

        drawContours(out_image, contours, static_cast<int>(i), Scalar(255), 2, 8);
    }

    file_lanes(out_image, result);
}

