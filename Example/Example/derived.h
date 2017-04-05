#ifndef derived_h
#define derived_h


#include "base.h"

struct derived : base {
	derived(int x, int y) : base(x, y) { std::cout << "derived " << x * 2 << " " << y * 2 << "\n"; }

	//inline const static RegisterBase<derived> reg{ "derived" };   // C++17, macro can be used to eliminate type name repition as string
	// pre-C++17, initialize in .cpp file
	//static RegisterBase<derived> reg;
	static Register<derived> reg; 
};


#endif//derived_h