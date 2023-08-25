/*
example (error when template funtion receive not integer type)
*/

template <typename T>
T Sum(T a, T b) {
    static_assert(std::is_integral_v<T>, "parameter is not integer");
    return a + b;
}

template <typename T, typename = enable_if_t<is_integral_v<T>>>
T Sum(T a, T b) {

    return a + b;
}
