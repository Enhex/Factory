# Factory
Generic factory that can instantiate unknown types by value.

## Example
```C++
#include <iostream>
#include <Factory.h>

struct base {
  base() { std::cout << "base\n"; }
};

// select base and key types once using an alias
using FactoryBase = Factory<base, std::string>;

template<typename Derived>
using RegisterBase = Register<base, std::string, Derived>;


struct derived : base {
  derived() { std::cout << "derived\n"; }

  // Register a factory for the derived class
  static RegisterBase<derived> reg; // pre-C++17, initialize in .cpp file
  // C++17
  //inline static RegisterBase<derived> reg{ "derived" };
};
RegisterBase<derived> derived::reg("derived");


int main()
{
  // instantiate an instance of derived and get a unique_ptr to base
  auto d = FactoryBase::create("derived");
}
```

[more detailed example](Example/Example).
