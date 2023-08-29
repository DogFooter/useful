#include <iostream>
#include <string>

/* 해당 문자가 정수인지 실수인지 판별 */
class CFindStrType {
    static enum strType { integer, noneInteger, unknown };
public:

    static strType returnStringType(std::string_view s) {


        for (char c : s) {
            if ((!std::isdigit(c)) && c != '.') {
                return unknown; // 숫자가 아닌 문자가 있으면 정수가 아님
            }
        }

        //숫자와 . 만 있을 때 
        switch (std::count(s.begin(), s.end(), '.')) {
        case 0:
            return integer;
        case 1:
            return noneInteger;
        default:
            return unknown;
        }
    }



};



/* testcode */
int main() {

    std::string str1 = "123";
    std::string str2 = "12.34";
    std::string str3 = ".1256c";

    auto result = CFindStrType::returnStringType(str1);
    result = CFindStrType::returnStringType(str2);
    result = CFindStrType::returnStringType(str3);


    return 0;
}