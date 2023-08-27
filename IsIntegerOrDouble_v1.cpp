#include <iostream>
#include <string>

/* 해당 문자가 정수인지 실수인지 판별 */
bool isInteger(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; // 숫자가 아닌 문자가 있으면 정수가 아님
        }
    }
    return true;
}


//testcode
int main() {
    std::string str1 = "123";
    std::string str2 = "12.34";

    if (str2.find('.') != std::string::npos) {
        std::cout << "str2 is a double: " << str2 << std::endl;
    }
    else if (isInteger(str2)) {
        std::cout << "str2 is an integer: " << str2 << std::endl;
    }
    else {
        std::cout << "str2 is neither an integer nor a double: " << str2 << std::endl;
    }

    return 0;
}