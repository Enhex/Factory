#ifndef base_h
#define base_h


#include <iostream>
#include <Factory.h>

struct base {
	base(int x, int y) { std::cout << "base " << x << " " << y << "\n"; }

	// intrusive approaches
	using factory = Factory<base, std::string, int, int>;
	
	static auto create(std::string key, int x, int y) {
		return Factory<base, std::string, int, int>::create(key, x, y);
	}

	template<typename Derived>
	using Register = Register<base, std::string, Derived, int, int>;
};

// non-intrusive approaches
using FactoryBase = Factory<base, std::string, int, int>;

auto base_factory(std::string key, int x, int y) { return Factory<base, std::string, int, int>::create(key, x, y); }

template<typename Derived>
using RegisterBase = Register<base, std::string, Derived, int, int>;


#endif//base_h