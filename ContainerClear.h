#include <vector>

// receive n vectors and clear all
template<typename ... Ts>
void vectorsClear(Ts& ... args) {
	(args.clear(), ...);

};
