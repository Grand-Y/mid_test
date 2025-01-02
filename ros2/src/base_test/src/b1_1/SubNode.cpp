#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "base_test/msg/str_msg.hpp"
// include "/ros2/a_mid_test/ros2/src/base_test/install/base_test/include/base_test/base_test/msg/str_msg.hpp"
using std::placeholders::_1;

class SubNode : public rclcpp::Node
{
public:
    SubNode() : Node("SubNode") {
        subscription_ = this->create_subscription<base_test::msg::StrMsg>(
            "b1_1", 10, std::bind(&SubNode::topic_callback, this, _1));
    }

    ~SubNode() {
        write_logs();
    }

private:
    rclcpp::Subscription<base_test::msg::StrMsg>::SharedPtr subscription_;
    std::vector<uint64_t> tra_latency;
    std::ofstream ofs;

    void write_logs() {
        std::string log_path = "/ros2/a_mid_test/ros2/src/base_test/src/b1_1/log";
        RCLCPP_INFO(this->get_logger(), "start writing logs, log_path: '%s'", log_path.c_str());
        RCLCPP_INFO(this->get_logger(), "tra_log num: : '%ld'", tra_latency.size());

        // 写入延迟日志
        ofs.open(log_path + "/tra_" + "Sub1_1", std::ios::trunc);
        for (size_t j = 0; j < tra_latency.size(); j ++ )
            ofs << tra_latency[j] << std::endl;
        ofs.close();

        RCLCPP_INFO(this->get_logger(), "writing logs finished");
    }

    void topic_callback(const base_test::msg::StrMsg::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->str.c_str());
        uint64_t tra_l = (this->now() - msg->header.stamp).nanoseconds();
        tra_latency.push_back(tra_l);
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubNode>());
    rclcpp::shutdown();
    return 0;
}