#include <memory>
#include <opencv2/opencv.hpp>
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::Bbox;

std::shared_ptr<YoloResult> yolo_detect(cv::Mat &frame);