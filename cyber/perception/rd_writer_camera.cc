#include "cyber/cyber.h"
#include "cyber/examples/proto/examples.pb.h"
#include "cyber/time/rate.h"
#include "cyber/time/time.h"
#include <chrono>
#include <ctime>

using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::cyber::examples::proto::Driver;

int main(int argc, char *argv[]) {
  // init cyber framework
  apollo::cyber::Init(argv[0]);
  // create talker node
  auto talker_node = apollo::cyber::CreateNode("rd_writer_camera");
  // create talker
  auto talker = talker_node->CreateWriter<Driver>("/apollo/camera");
  Rate rate(2.0);

  int a = 0;

  std::string content("rd_camera");
  while (apollo::cyber::OK()) {
    static uint64_t seq = 0;

    auto msg = std::make_shared<Driver>();
    msg->set_timestamp(Time::Now().ToNanosecond());
    msg->set_msg_id(seq++);
    msg->set_content(content + std::to_string(seq - 1));
    talker->Write(msg);

    AINFO << "/apollo/camera sent message, seq=" << (seq - 1) << "--------------;";
    rate.Sleep();
    a ++ ;
    AINFO << a;
    if (a == 20) break;
  }
  return 0;
}
