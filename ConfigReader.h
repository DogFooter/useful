#include <iostream>
#include <fstream>
#include <string>
#include <map>

class ConfigReader {
private:
    std::string whiteSpace = " ";
    std::map<std::string, std::string> paths;
    std::string trim(std::string& str) {

    }
public:
    ConfigReader(const std::string& configFile) {
        std::ifstream file(configFile);
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
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
