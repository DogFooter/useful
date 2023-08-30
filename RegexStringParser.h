#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>


//fileNameParser
class RegexStringParser {

public:
    static std::vector<std::string> extractParsingData(const std::regex& reg, const std::string& input) {
        std::smatch matches;
        std::vector<std::string> extractedData;

        if (std::regex_match(input, matches, reg)) {

            for (size_t i = 1; i < matches.size(); ++i) {
                extractedData.emplace_back(matches[i]);
            }
            return extractedData;
        }

        // ��ġ���� ���� ��� �� ���� ��ȯ
        return {};
    }

};

//test code
int main() {
    std::regex format(R"(([^_]+)_T(\d+)_t(\d+)_S([\d.]+)_([\d.]+)\.(.*))"); // ��Ҹ� �����ϴ� ���� ǥ����
    std::string input = "nicesd113_T20230812_t12067799_S2500000.89_45.6.mi"; // example

    auto result = RegexStringParser::extractParsingData(format, input);

    for (const std::string& data : result) {
        std::cout << data << std::endl;
    }

    return 0;
}