# Basics

When you make a comparable type you usually only need to implement `operator <`: c++ std::sort and containers use this operator only.
But when you compare your type in other places, you want all operators for easy of use. Of course, you do not want to implement them by yourself,
you want them to be implemented using your `operator <`. Well, here you are.

# MakeComparable

MakeComparable is a c++ template than from a type with `operator <` (and possibly some other comparison operators) makes new type with full support of comparison: `<`, `<=`, `>`, `>=`, `==` and `!=`.
C++ concepts and SFINAE make possible to use your existing operators and make new only for missing ones: for example, you may want to explicitly implement `operator ==` and `operator !=` for performance reasons.


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

