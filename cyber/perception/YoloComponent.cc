#include <fstream>
#include <memory>
#include <vector>
#include <opencv2/opencv.hpp>
#include "cyber/a_mid_test/cyber/perception/YoloComponent.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"
#include "cyber/time/time.h"
#include "yolo_detect.h"

using apollo::cyber::Time;
using apollo::cyber::a_mid_test::cyber::Frame;
using apollo::cyber::a_mid_test::cyber::OcvMat;
using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::Bbox;


bool YoloComponent::Init() {
    component_name = node_->Name();
    for(int i = 0; i < 1; i ++ ){
        std::vector<uint64_t> tmp;
        tra_latency.push_back(tmp);
    }

    writer1 = node_->CreateWriter<YoloResult>("/" + component_name);
    return true;
}

bool YoloComponent::Proc(const std::shared_ptr<Frame>& msg0) {
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

    std::shared_ptr<YoloResult> to_send = nullptr;

    uint64_t cal_start_time = Time::Now().ToNanosecond();
    try {
        to_send = yolo_detect(m);
    } catch (const std::exception &e) {
        AWARN << "Something wrong in yolo detection.";
        AWARN << e.what();
    }
    uint64_t cal_finish_time = Time::Now().ToNanosecond();
    cal_latency.push_back(cal_finish_time - cal_start_time);

    auto to_send_mat = new OcvMat(msg0->mat());
	to_send->set_allocated_mat(to_send_mat);
    to_send->set_timestamp(Time::Now().ToNanosecond());
    writer1->Write(to_send);

    // AINFO << "Yolo";

    return true;
}