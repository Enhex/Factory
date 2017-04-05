#include "derived.h"

base::Register<derived> derived::reg("derived");

int main()
{
	auto d1 = FactoryBase::create("derived", 1, 2);
	auto d2 = base::factory::create("derived", 1, 2);
	auto d3 = base_factory("derived", 1, 2);
	auto d4 = base::create("derived", 1, 2);
}