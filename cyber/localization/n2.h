#include <memory>
#include <chrono>
#include <fstream>
#include <string>

#include "cyber/component/component.h"
#include "cyber/examples/proto/examples.pb.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::examples::proto::Driver;

class n2 : public Component<Driver> {
public:
  bool Init() override;
  bool Proc(const std::shared_ptr<Driver>& msg0) override;

private:
  std::ofstream ofs;
  std::string fn;
  std::vector<std::vector<uint64_t>> tra_latency;
	std::vector<std::vector<uint64_t>> cal_latency;

  ~n2() {
    AINFO << fn << "destoryed";
    AINFO << "Start writing logs";

    write_logs();
    AINFO << "Writing logs finished";
    AINFO << fn << "end";
  }

  void write_logs() {
    std::string base_path = "/apollo/cyber/a_mid_test/cyber/logs/";

    if (tra_latency.size() != cal_latency.size()) {
      AERROR << "Error: tra_latency and cal_latency must have the same size.";
      return;
    }

    // Iterate over the outer vector
    for (size_t i = 0; i < tra_latency.size(); ++i) {
      std::string file_path = base_path + fn + '_' + std::to_string(i);
      std::ofstream ofs(file_path, std::ios::trunc);
      if (!ofs.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        continue;
      }

      // Check that tra_latency[i] and cal_latency[i] have the same size
      if (tra_latency[i].size() != cal_latency[i].size()) {
        std::cerr << "Error: tra_latency[" << i << "] and cal_latency[" << i << "] must have the same size." << std::endl;
        continue;
      }

      // Write each entry to the file
      for (size_t j = 0; j < tra_latency[i].size(); ++j) {
        ofs << tra_latency[i][j] << ", " << cal_latency[i][j] << ", p" << std::endl;
      }

      ofs.close();
    }
  }

};
CYBER_REGISTER_COMPONENT(n2)
