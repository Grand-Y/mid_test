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
  auto talker_node = apollo::cyber::CreateNode("rd_writer_lidar");
  // create talker
  auto talker = talker_node->CreateWriter<Driver>("/apollo/lidar");
  Rate rate(2.0);

  int a = 0;

  std::string content("rd_lidar");
  while (apollo::cyber::OK()) {
    static uint64_t seq = 0;
    auto msg = std::make_shared<Driver>();
    msg->set_timestamp(Time::Now().ToNanosecond());
    msg->set_msg_id(seq++);
    msg->set_content(content + std::to_string(seq - 1));

    auto now = std::chrono::system_clock::now();

    // 将时间点转换为时间戳
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // 提取微秒部分
    auto duration = now.time_since_epoch();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 1000000;

    // 转换为本地时间
    std::tm now_tm = *std::localtime(&now_time_t);

    // 打印格式化的时间戳，精确到微秒
    std::cout << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S")
              << '.' << std::setfill('0') << std::setw(6) << micros
              << std::endl;

    talker->Write(msg);
    AINFO << "/apollo/lidar sent message, seq=" << (seq - 1) << ";";
    rate.Sleep();
    a ++ ;
    AINFO << a;
    if (a == 20) break;
  }
  return 0;
}
