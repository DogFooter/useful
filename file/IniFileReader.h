#include <iostream>
#include <fstream>
#include <string>
#include <map>

constexpr const char* iniFilePath = "D:\\";

class IniFileReader {
private:
    std::map<std::string, std::string> paths; 
protected:
    std::string trim(const std::string& str) { // 좌우공백 제거 
	        std::string whiteSpace = " ";
        size_t start = str.find_first_not_of(whiteSpace);
        size_t end = str.find_last_not_of(whiteSpace);

        return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
		
    }
public:
    IniFileReader(const std::string_view configFile) {
        std::ifstream file(configFile.data());
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
			            if (pos != std::string::npos) {
                std::string key = trim(line.substr(0, pos));
                std::string value = trim(line.substr(pos + 1));
                paths[key] = value;
            }
        }
    }
	    std::string getPath(const std::string& key) {
        if (paths.find(key) != paths.end())
            return paths[key];
        else
            return std::string();
    }
};
