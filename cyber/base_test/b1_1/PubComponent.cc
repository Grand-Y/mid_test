#include <memory>
#include <string>
#include <glob.h>
#include <fstream>
#include <iostream>
#include <thread>
#include "cyber/class_loader/class_loader.h"
#include "cyber/component/component.h"
#include "cyber/a_mid_test/cyber/amt_msg.pb.h"
#include "cyber/component/timer_component.h"
#include "cyber/time/time.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::TimerComponent;
using apollo::cyber::Time;
using apollo::cyber::Writer;
using apollo::cyber::a_mid_test::cyber::BaseString;

class PubComponent : public TimerComponent {
	private:
		std::string content;
		size_t current_index = 0;
		size_t count = 1000;

		std::shared_ptr<Writer<BaseString>> writer1 = nullptr;
		bool flag = true;


	public:
		bool Init() {
			AINFO<<"node name:"<<node_->Name();
			
			writer1 = node_->CreateWriter<BaseString>("/b1_1");


			return true;
		}

		bool Proc() {
			// AINFO << current_index ++ ;
			current_index ++ ;
			content = generateRandomString("15m");
			auto to_send = std::make_shared<BaseString>();
			to_send->set_timestamp(Time::Now().ToNanosecond());
			to_send->set_str(content);
			writer1->Write(to_send);

			if (current_index == count) {
				AINFO << "End";
			}

			return true;
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
CYBER_REGISTER_COMPONENT(PubComponent)
