#include <memory>
#include <fstream>
#include <string>
#include <vector>

#include "cyber/component/component.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::Writer;
using apollo::cyber::a_mid_test::cyber::BaseString;

class SubComponent : public Component<BaseString> {
public:
    bool Init() override;
    bool Proc(const std::shared_ptr<BaseString>& msg0) override;
private:
    std::ofstream ofs;
    std::string component_name;
    std::vector<std::vector<uint64_t>> tra_latency;

    std::vector<std::string> logs = {"Pub"};

    ~SubComponent() {
        AINFO << component_name << " destoryed";
        write_logs();
        AINFO << component_name << " end";
    }

    void write_logs() {
        std::string log_path = "/apollo/cyber/a_mid_test/cyber/base_test/b1_1/logs";
        AINFO << component_name << " start writing logs, log_path: " << log_path;
        AINFO << component_name << " tra_log num: " << tra_latency[0].size();

        // 写入延迟日志
        for (size_t i = 0; i < tra_latency.size(); i ++ ) {
            ofs.open(log_path + "/tra_" + component_name + "_" + logs[i], std::ios::trunc);
            for (size_t j = 0; j < tra_latency[i].size(); j ++ )
                ofs << tra_latency[i][j] << std::endl;
            ofs.close();
        }

        ofs.close();

        AINFO << component_name << " writing logs finished";
    }
};
CYBER_REGISTER_COMPONENT(SubComponent)
