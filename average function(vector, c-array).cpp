#include <vector>
#include <iostream>
#include <type_traits>
#include <numeric>

/*
average function(vector, c-array)
*/
template<typename T>
typename T::value_type average(T& stlContainer) {

    return accumulate(stlContainer.begin(), stlContainer.end(), 0);
}

template<typename T, int N>
T average(T(&ptr)[N]) {
    T sum = 0;
    //cout << __FUNCSIG__ << endl;
    for (T a : ptr)
        sum += a;

    return sum;
}
/* test code */
int main() {
    
    int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

    std::cout << average(x) << std::endl;
    std::cout << average(v) << std::endl;

}