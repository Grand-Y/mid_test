#include <memory>
#include <fstream>
#include <string>
#include <vector>


#include "cyber/component/component.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::Writer;
using apollo::cyber::a_mid_test::cyber::LaneResult;
using apollo::cyber::a_mid_test::cyber::YoloResult;
using apollo::cyber::a_mid_test::cyber::TrackResult;

class FinalComponent : public Component<LaneResult, YoloResult, TrackResult> {
public:
    bool Init() override;
    bool Proc(const std::shared_ptr<LaneResult>& msg0, 
              const std::shared_ptr<YoloResult>& msg1,
              const std::shared_ptr<TrackResult>& msg2) override;
private:
    std::ofstream ofs;
    std::string component_name;
    std::vector<std::vector<uint64_t>> tra_latency;

    bool is_tracker_init = false;

    ~FinalComponent() {
        AINFO << component_name << " destoryed";
        write_logs();
        AINFO << component_name << " end";
    }

    void write_logs() {
        AINFO << component_name << " start writing logs";
        AINFO << component_name << " tra_log num: " << tra_latency[0].size();

        std::string log_path = std::string(std::getenv("LOG_PATH"));

        // 写入延迟日志
        for (size_t i = 0; i < tra_latency.size(); i ++ ) {
            ofs.open(log_path + "/tra_" + component_name + "_" + std::to_string(i), std::ios::trunc);
            for (size_t j = 0; j < tra_latency[i].size(); j ++ )
                ofs << tra_latency[i][j] << std::endl;
            ofs.close();
        }

        ofs.close();
        
        AINFO << component_name << " writing logs finished";
    }
};
CYBER_REGISTER_COMPONENT(FinalComponent)
