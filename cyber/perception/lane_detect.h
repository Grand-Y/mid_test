#include <opencv2/opencv.hpp>

// #include "cyber/a_mid_test/cyber/amt_msg.pb.h"

// using apollo::cyber::a_mid_test::cyber::Point;
using namespace cv;

void lane_process(cv::Mat &frame, Point *result);