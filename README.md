# Factory
Generic factory that can instantiate unknown types by value.

## Example
```C++
#include <iostream>
#include <Factory.h>

struct base {
  base() { std::cout << "base\n"; }
};

using FactoryBase = Factory<base, std::string>;

template<typename Derived>
using RegisterBase = Register<base, std::string, Derived>;


struct derived : base {
  derived() { std::cout << "derived\n"; }

  // C++17, macro can be used to eliminate type name repition as string
  //inline const static RegisterBase<derived> reg{ "derived" };
  // pre-C++17, initialize in .cpp file
  static RegisterBase<derived> reg;
};
RegisterBase<derived> derived::reg("derived");


int main()
{
    auto d = FactoryBase::create("derived");
}
```

[more detailed example](Example/Example).
