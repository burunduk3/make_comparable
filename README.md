# Basics

When you make a comparable type you usually only need to implement `operator <` for it: c++ std::sort and container use this one only.
But when you want to you comparison in other places, you want all operators for easy of use. Of course, you do not want to implement them by yourself,
you want them to be implemented using your `operator <`. Well, here you are.

# MakeComparable

MakeComparable is a c++ template than from a type with `operator <` (and possibly some other comparison operators) new type with full support of comparison: `<`, `<=`, `>`, `>=`, `==` and `!=`.
C++ concepts and SFINAE made possible to use your operator when possible and make new only for missing ones.


# Requirements

MakeComparable uses [Concepts TS](http://en.cppreference.com/w/cpp/language/constraints), so you need modern compiler to use it. `gcc-6.1` or higher is ok, but you have to pass `-fconcepts` to it.


# Usage

```c++
#include "make_comparable.h++"

class YourClassStub {
  public:
    bool operator < ( const YourClassStub & ) const;
    // You have to implement 'operator <' and you may (but do not have to) implement any other.
  ...
};

typedef make_comparable::MakeComparable <YourClassStub> YourClass;
// Now you have YouClass with six comparison operators, ready to use.
```

See also `example.c++`.

