#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "base_test/msg/str_msg.hpp"
// #include "/ros2/a_mid_test/ros2/src/base_test/install/base_test/include/base_test/base_test/msg/str_msg.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class PubNode : public rclcpp::Node
{
public:
    PubNode() : Node("PubNode"), count_(0) {
        publisher_ = this->create_publisher<base_test::msg::StrMsg>("b1_1", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::timer_callback, this));
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<base_test::msg::StrMsg>::SharedPtr publisher_;
    size_t count_;

    void timer_callback() {
        // auto message = base_test::msg::StrMsg();
        auto message = std::make_unique<base_test::msg::StrMsg>();
        message->str = generateRandomString("1k");
        message->header.stamp = this->now();

        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message->str.c_str());
        publisher_->publish(move(message));
    }

    long long parseSize(const std::string& sizeStr) {
        char unit = sizeStr.back();
        long long size = std::stoll(sizeStr.substr(0, sizeStr.size() - 1));
        
        switch (unit) {
            case 'K':
            case 'k':
                return size * 1024;
            case 'M':
            case 'm':
                return size * 1024 * 1024;
            case 'G':
            case 'g':
                return size * 1024 * 1024 * 1024;
            default:
                return size; // Assume bytes if no unit
        }
    }

    std::string generateRandomString(const std::string& sizeStr) {
        long long size = parseSize(sizeStr);
        std::string randomString;
        randomString.reserve(size);

        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t maxIndex = sizeof(charset) - 1;

        srand(static_cast<unsigned int>(time(0)));
        
        for (long long i = 0; i < size; ++i) {
            randomString += charset[rand() % maxIndex];
        }

        return randomString;
    }

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PubNode>());
    rclcpp::shutdown();
    return 0;
}