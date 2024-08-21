#include <fstream>
#include <memory>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include "cyber/time/time.h"
#include "cyber/a_mid_test/cyber/perception/TrackerComponent.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::Time;
using apollo::cyber::a_mid_test::cyber::Frame;
using apollo::cyber::a_mid_test::cyber::OcvMat;
using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::Bbox;
using apollo::cyber::a_mid_test::cyber::TrackResult;

bool TrackerComponent::Init() {
    component_name = node_->Name();
    for(int i = 0; i < 2; i ++ ){
        std::vector<uint64_t> tmp;
        tra_latency.push_back(tmp);
    }

    writer1 = node_->CreateWriter<TrackResult>("/" + component_name);
    cv_tracker = cv::TrackerKCF::create();
    return true;
}

bool TrackerComponent::Proc(const std::shared_ptr<Frame>& msg0, 
                            const std::shared_ptr<YoloResult>& msg1) {
    uint64_t receive_time = Time::Now().ToNanosecond();
    // AINFO << "tracker transfer time:" << receive_time - msg0->timestamp();
    tra_latency[0].push_back(receive_time - msg0->timestamp());
    tra_latency[1].push_back(receive_time - msg1->timestamp());

    cv::Mat m;
    OcvMat content = msg0->mat();
    m.create(content.rows(), content.cols(), content.elt_type());
    size_t dataSize = content.rows() * content.cols() * content.elt_size();
    std::copy(reinterpret_cast<unsigned char *>(
                  const_cast<char *>(content.mat_data().data())),
              reinterpret_cast<unsigned char *>(
                  const_cast<char *>(content.mat_data().data()) + dataSize),
              m.data);

    uint64_t alog_start_time = Time::Now().ToNanosecond();
    if (!is_tracker_init) {
        is_tracker_init = true;
        auto bbox_size = msg1->bboxresult_size();
        if (bbox_size <= 0) {
            // AINFO << "random place";
            result_box = cv::Rect2d(287, 23, 86, 320);
        } else {
            Bbox tmp_box = msg1->bboxresult(0);
            AINFO << "tmp_box.x:" << tmp_box.x() << " y:" << tmp_box.y() << " w:" << tmp_box.w() << " h:" << tmp_box.h();
            result_box = cv::Rect2d(double(tmp_box.x()), double(tmp_box.y()), double(tmp_box.w()), double(tmp_box.h()));
        }
        content = msg1->mat();
        m.create(content.rows(), content.cols(), content.elt_type());
        size_t dataSize = content.rows() *  content.cols() * content.elt_size();
        std::copy(reinterpret_cast<unsigned char *>(const_cast<char *>(content.mat_data().data())),
                reinterpret_cast<unsigned char *>(const_cast<char *>(content.mat_data().data()) + dataSize),
                m.data);
        AINFO << "init tracker";
        cv_tracker->init(m, result_box);
    } else {
        if (!cv_tracker->update(m, result_box)) {
            is_tracker_init = true;
            // AINFO << "lose one";
        }
        // AINFO << "tracker cost time" << Time::Now().ToNanosecond() - alog_start_time;
    }
    uint64_t cal_finish = Time::Now().ToNanosecond();

    cal_latency.push_back(cal_finish - alog_start_time);

    auto to_send = std::make_shared<TrackResult>();
    auto track_box = to_send->mutable_trackresult();
    track_box->set_x(result_box.x);
    track_box->set_y(result_box.y);
    track_box->set_width(result_box.width);
    track_box->set_height(result_box.height);
    to_send->set_timestamp(Time::Now().ToNanosecond());
    writer1->Write(to_send);

    return true;
}

