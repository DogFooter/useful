#include "directoryMoniter.h"


void directoryMoniter::MonitorDirectory() {

	while (true) {
		for (const auto& entry : fs::directory_iterator(dirPath)) {
			if (is_regular_file(entry)) {
				std::string filename = fs::path(entry.path().string()).string();

				if (!checkfile(filename) && !predicate(filename)) {
					excute(filename);
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(interval_sec));  // 1분 대기
	}


}
