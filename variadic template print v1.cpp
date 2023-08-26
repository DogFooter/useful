
#include <vector>
#include <iostream>
#include <type_traits>
#include <numeric>
#include <string>
#include <exception>

/* variadic template print v1 */

template<typename ...Ts, int N>
void cpp_print(const char(&s)[N], Ts...args) noexcept(false) {
    std::string arr[] = { std::to_string(args)... };
    std::string temp(s);
    std::string outputStr;

    int i = 0;
    //int idxBefore = 0;
    for (size_t idx = 0; idx != std::string::npos; idx = temp.find("%d", idx), ++i) {
        //outputStr += temp.substr(idxBefore,idx - idxBefore);
        if (i == sizeof...(args))
            throw std::invalid_argument("인자가 너무 적습니다");
        outputStr += arr[i];
        //idxBefore = idx++;
    }
    if (i < sizeof...(args))
        throw std::invalid_argument("인자가 너무 많습니다");

    //outputStr += temp.substr(idxBefore + 1);
    std::cout << outputStr << std::endl;


}

/* example code */
int main() {

    try {
        cpp_print("%d%d%d\n", 1, 2, 3);
        cpp_print("%d%d\n", 1, 2, 3);
        cpp_print("%d%d\n", 1);
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;
    }

}
