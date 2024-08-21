#include "cyber/a_mid_test/cyber/localization/n2.h"
#include "cyber/time/time.h"

using apollo::cyber::Time;

bool n2::Init() {
  AINFO << "-------------n2 init";
  fn = node_->Name();
  for(int i=0;i<1;i++){
    std::vector<uint64_t> tmp;
    tra_latency.push_back(tmp);
  }
  return true;
}

bool n2::Proc(const std::shared_ptr<Driver>& msg0) {
  AINFO << "--------------Next received msg [" << msg0->msg_id() << "] ["
        << msg0->content() << "]";

  uint64_t receive_time = Time::Now().ToNanosecond();
  AINFO << "tracker transfer time:" << receive_time - msg0->timestamp();
  tra_latency[0].push_back(receive_time - msg0->timestamp());
  
  return true;
}
