#include <vector>

// receive n vectors and clear all
template<typename ... Ts>
void vectorsClear(Ts& ... args) {
	(args.clear(), ...);

};


// Clear arrays
template<typename T, size_t N>
void arrayClear(T(&arr)[N]) {
	for (size_t i = 0; i < N; ++i) {
		arr[i] = T{};
	}
}

template<typename... Ts, size_t... Ns>
void arraysClear(Ts(&... args)[Ns]) {
	((arrayClear(args)), ...);
}
