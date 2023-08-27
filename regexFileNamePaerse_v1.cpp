#include <iostream>
#include <string>
#include <regex>


/* �����̸� �Ľ� v1 */
int main() {
    std::string input = "S0003_T20230411_F5666600_R6.555";
    std::regex pattern("(S\\d+)_T(\\d+)_F(\\d+)_R([\\d.]+)");

    std::smatch matches;
    if (std::regex_match(input, matches, pattern)) {
        int sValue = std::stoi(matches[1]);
        int tValue = std::stoi(matches[2]);
        int fValue = std::stoi(matches[3]);
        double rValue = std::stod(matches[4]);

        std::cout << "S (int): " << sValue << std::endl;
        std::cout << "T (int): " << tValue << std::endl;
        std::cout << "F (int): " << fValue << std::endl;
        std::cout << "R (double): " << rValue << std::endl;
    }
    else {
        std::cout << "���ϰ� ��ġ�ϴ� ���ڿ��� �����ϴ�." << std::endl;
    }

    return 0;
}
