#include <fstream>
#include <memory>
#include <vector>
#include "cyber/time/time.h"
#include "cyber/a_mid_test/cyber/perception/FinalComponent.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::Time;
using apollo::cyber::a_mid_test::cyber::LaneResult;
using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::TrackResult;

bool FinalComponent::Init() {
    component_name = node_->Name();
    for(int i = 0; i < 3; i ++ ){
        std::vector<uint64_t> tmp;
        tra_latency.push_back(tmp);
    }

    return true;
}

bool FinalComponent::Proc(const std::shared_ptr<LaneResult>& msg0, 
                          const std::shared_ptr<YoloResult>& msg1,
                          const std::shared_ptr<TrackResult>& msg2) {
    uint64_t receive_time = Time::Now().ToNanosecond();
    // AINFO << "tracker transfer time:" << receive_time - msg0->timestamp();
    tra_latency[0].push_back(receive_time - msg0->timestamp());
    tra_latency[1].push_back(receive_time - msg1->timestamp());
    tra_latency[2].push_back(receive_time - msg2->timestamp());


    return true;
}

