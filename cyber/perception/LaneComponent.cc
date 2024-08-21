#include <fstream>
#include <memory>
#include <vector>
#include <opencv2/opencv.hpp>
#include "cyber/time/time.h"
#include "cyber/a_mid_test/cyber/perception/LaneComponent.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"
#include "lane_detect.h"

using apollo::cyber::Time;
using apollo::cyber::a_mid_test::cyber::Frame;
using apollo::cyber::a_mid_test::cyber::LaneResult;
using apollo::cyber::a_mid_test::cyber::OcvMat;


bool LaneComponent::Init() {
    component_name = node_->Name();
    for(int i = 0; i < 1; i ++ ){
        std::vector<uint64_t> tmp;
        tra_latency.push_back(tmp);
    }

    writer1 = node_->CreateWriter<LaneResult>("/" + component_name);
    return true;
}

bool LaneComponent::Proc(const std::shared_ptr<Frame>& msg0) {
    uint64_t receive_time = Time::Now().ToNanosecond();
    // AINFO << "tracker transfer time:" << receive_time - msg0->timestamp();
    tra_latency[0].push_back(receive_time - msg0->timestamp());

    // 还原 Mat 数据
    cv::Mat m;
    OcvMat content = msg0->mat();
    m.create(content.rows(), content.cols(), content.elt_type());
    size_t dataSize = content.rows() * content.cols() * content.elt_size();
    std::copy(reinterpret_cast<unsigned char *>(
                  const_cast<char *>(content.mat_data().data())),
              reinterpret_cast<unsigned char *>(
                  const_cast<char *>(content.mat_data().data()) + dataSize),
              m.data);

    cv::Point *result = new cv::Point[4];

    // 方法调用并计算时间
    uint64_t cal_start_time = Time::Now().ToNanosecond();
    try {
        lane_process(m, result);
    } catch (const std::exception &e) {
        AINFO << "Something wrong in lane detection.";
        AINFO << e.what();
    }
    uint64_t cal_finish_time = Time::Now().ToNanosecond();
    cal_latency.push_back(cal_finish_time - cal_start_time);

    // 处理发送内容
    auto to_send = std::make_shared<LaneResult>();
    auto left1 = to_send->mutable_left1();
    left1->set_x(result[0].x);
    left1->set_y(result[0].y);
    auto left2 = to_send->mutable_left2();
    left2->set_x(result[1].x);
    left2->set_y(result[1].y);
    auto right1 = to_send->mutable_right1();
    right1->set_x(result[2].x);
    right1->set_y(result[2].y);
    auto right2 = to_send->mutable_right2();
    right2->set_x(result[3].x);
    right2->set_y(result[3].y);
    to_send->set_timestamp(Time::Now().ToNanosecond());
    writer1->Write(to_send);

    // AINFO << "Lane";

    return true;
}