#pragma once

#include <iostream>
#include <random>

//mersenne engine

template <typename T>
class RandNumGenerator {
    std::random_device seed;
    std::mt19937 engine;
    typename std::conditional<std::is_integral<T>::value, std::uniform_int_distribution<T>, std::uniform_real_distribution<T>>::type dist;

public:
    RandNumGenerator(T start, T end)
        : engine(seed()), dist(start, end)
    { }

    T generate() {
        return dist(engine);
    }
};

//test code
//int main()
//{
//    RandNumGenerator mine(5.666, 14.7888);
//    for (int i = 0; i < 15; ++i)
//        std::cout << mine.generate() << std::endl;
//
//}
