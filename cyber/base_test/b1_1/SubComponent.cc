#include <memory>
#include <string>
#include <glob.h>
#include <fstream>
#include <iostream>
#include <thread>
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"
#include "cyber/time/time.h"
#include "SubComponent.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::TimerComponent;
using apollo::cyber::Time;
using apollo::cyber::Writer;
using apollo::cyber::a_mid_test::cyber::BaseString;

bool SubComponent::Init() {
	component_name = node_->Name();
    for(int i = 0; i < 1; i ++ ){
        std::vector<uint64_t> tmp;
        tra_latency.push_back(tmp);
    }

    return true;
}

bool SubComponent::Proc(const std::shared_ptr<BaseString>& msg0) {
	uint64_t receive_time = Time::Now().ToNanosecond();
	// AINFO << receive_time - msg0->timestamp();
    tra_latency[0].push_back(receive_time - msg0->timestamp());

	return true;
}
