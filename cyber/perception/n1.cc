#include <string>

#include "cyber/a_mid_test/cyber/perception/n1.h"
#include "cyber/time/time.h"

using apollo::cyber::Time;

bool n1::Init() {
  AINFO << "-------------n1 init";
  fn = node_->Name();
  for(int i=0;i<3;i++){
    std::vector<uint64_t> tmp;
    tra_latency.push_back(tmp);
  }
  for(int i=0;i<3;i++){
    std::vector<std::string> tmp;
    cal_latency.push_back(tmp);
  }
  return true;
}

bool n1::Proc(const std::shared_ptr<Driver>& msg0,
              const std::shared_ptr<Driver>& msg1, 
              const std::shared_ptr<Driver>& msg2) {
  uint64_t receive_time = Time::Now().ToNanosecond();
  AINFO << "tracker transfer time:" << receive_time - msg0->timestamp();
  tra_latency[0].push_back(receive_time - msg0->timestamp());
  tra_latency[1].push_back(receive_time - msg1->timestamp());
  tra_latency[2].push_back(receive_time - msg2->timestamp());
  AINFO << "====================================";
  cal_latency[0].push_back(msg0->content());
  cal_latency[1].push_back(msg1->content());
  cal_latency[2].push_back(msg2->content());
  AINFO << "-------------------------------------";

  a ++ ;
  if (a == 10) apollo::cyber::WaitForShutdown();

  AINFO << "Start common component Proc [" << msg0->msg_id() << "] ["
        << msg1->msg_id() << "] [" << msg2->msg_id() << "]";

  auto writer = node_->CreateWriter<Driver>("/apollo/n2");

  auto msg = std::make_shared<Driver>();
  msg->set_timestamp(Time::Now().ToNanosecond());
  msg->set_msg_id(0);
  msg->set_content("FAQ");

  writer->Write(msg);

  // AINFO << "send msg to next: FAQ";

  return true;
}
