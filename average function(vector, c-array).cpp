#include <vector>
#include <iostream>
#include <type_traits>
#include <numeric>

/*
average function(vector, c-array)
*/
template<typename T>
typename T::value_type average(T& stlContainer) {
    if (stlContainer.empty()) return 0; // prevent division by zero

    typename T::value_type sum = std::accumulate(stlContainer.begin(), stlContainer.end(), 0);
    return sum / stlContainer.size(); // calculate average by dividing the sum by the number of elements

}

template<typename T, int N>
T average(T(&ptr)[N]) {
    if (N == 0 ) return 0; // prevent division by zero

    T sum = 0;
    //cout << __FUNCSIG__ << endl;
    for (T a : ptr)
        sum += a;

    return sum / N ;
}
/* test code */
int main() {
    
    int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

    std::cout << average(x) << std::endl;
    std::cout << average(v) << std::endl;

}