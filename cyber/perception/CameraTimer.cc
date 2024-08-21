#include <memory>
#include <string>
#include <glob.h>
#include <fstream>
#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
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
using apollo::cyber::a_mid_test::cyber::Frame;
using apollo::cyber::a_mid_test::cyber::OcvMat;

class CameraTimer : public TimerComponent {
	private:
		std::vector<std::string> image_paths;
		size_t current_index = 0;

		std::shared_ptr<Writer<Frame>> writer1 = nullptr;
		bool flag = true;


	public:
		bool Init() {
			AINFO<<"camera node name:"<<node_->Name();
			
			writer1 = node_->CreateWriter<Frame>("/"+node_->Name());

			std::string data_path = std::string(std::getenv("DATA_PATH"));

			glob_t glob_result;
			glob((data_path + "/*.png").c_str(), GLOB_TILDE, nullptr, &glob_result);
			for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {
				image_paths.push_back(std::string(glob_result.gl_pathv[i]));
			}
			globfree(&glob_result);
			AINFO << "Init CameraTimer, image count is: " << image_paths.size();
			
			// 对路径进行排序以确保按顺序读取
			std::sort(image_paths.begin(), image_paths.end());

			return true;
		}

		bool Proc() {
			AINFO << current_index;
			if (current_index == image_paths.size()) {
				std::string workspace = std::string(std::getenv("WORKSPACE"));
				AINFO << "Finished, wait for end.";
				std::this_thread::sleep_for(std::chrono::seconds(10));
				std::ofstream flag_file("/apollo/cyber/a_mid_test/flag");
				flag_file.close();
				AINFO << "Wait for shutdown...";
				apollo::cyber::WaitForShutdown();
				return true;
			}
			// AINFO << image_paths[current_index];
			cv::Mat m = cv::imread(image_paths[current_index ++ ]);
			//Mat m;
			//if(!video.read(m))return false;
			auto serializableMat = new OcvMat;
			serializableMat->set_rows(m.rows);
			serializableMat->set_cols(m.cols);
			serializableMat->set_elt_type(m.type());
			serializableMat->set_elt_size((int)m.elemSize());

			size_t dataSize = m.rows * m.cols * m.elemSize();
			// AINFO << "image size: " << dataSize;
			serializableMat->set_mat_data(std::string((char*)m.data,(char*)m.data+dataSize));
			auto to_send = std::make_shared<Frame>();
			to_send->set_timestamp(Time::Now().ToNanosecond());
			to_send->set_allocated_mat(serializableMat);
			writer1->Write(to_send);

			return true;
		}
};
CYBER_REGISTER_COMPONENT(CameraTimer)
