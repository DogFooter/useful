#include <iostream>
#include <chrono>

int main() {
    std::cout << "High resolution clock period: "
        << std::chrono::high_resolution_clock::period().num
        << "/"
        << std::chrono::high_resolution_clock::period().den
        << " seconds" << std : endl;

    if (std::chrono::high_resolution_clock::is_steady)
        std::cout << "Clock is steady" << std::end;
    else
        std::clog << "Clock might be affected by wall clock adjustments";

    return 0;
}