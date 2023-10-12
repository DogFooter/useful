#pragma once
#include <chrono>
#include <iostream>


void functionMeasured(int a, std::string b, double c) {

}

template<typename Func, typename... Args>
void time_measurement_ns(Func f, int n_times, Args&&... args) {
    double total_time = 0.0;

    for (int i = 0; i < n_times; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        f(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> diff = end - start; // ns

        total_time += diff.count();
    }

    double average_time = total_time / n_times;

    std::cout << "Average time to run the function: " << average_time << " ns";
}

//exxample
int main() {
    const int num_executions = 50000;

    time_measurement_ns(functionMeasured, num_executions, 42, "Hello", 3.14);
}
