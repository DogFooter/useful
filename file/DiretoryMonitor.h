#pragma once
#include <fstream>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>
#include <functional>

namespace fs = std::filesystem;
using dm_callback = std::function<bool(const std::string&)>;

class directoryMoniter
{
	dm_callback checkfile = nullptr;
	dm_callback predicate = nullptr;
	dm_callback excute = nullptr;
	uint32_t interval_sec;
	std::string dirPath;

public:
	void setDirectoryPath(const std::string& path) { dirPath = path + "\\"; };
	void setInterval(uint32_t time) { interval_sec = time; };

	directoryMoniter(dm_callback checkfile, dm_callback predicate, dm_callback excute, const std::string& dirPath, uint32_t interval_sec = 60) :checkfile(checkfile), predicate(predicate), excute(excute), dirPath(dirPath), interval_sec(interval_sec) {
	};

	virtual void MonitorDirectory();

};
