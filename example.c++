#include <cstdio>
#include "make_comparable.h++"

int gcd ( int a, int b ) {
  return b == 0 ? a : gcd (b, a % b);
}

class RationalStub {
  private:
    int p, q;
  public:
    RationalStub ( int _p = 0, int _q = 1 ) : p (_p), q (_q) {
      int d = gcd (p, q);
      p /= d, q /= d;
    }
    // operator '<' is mandatory, all other are made from it
    bool operator < ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator <\n");
      return p * r.q < r.p * q;
    }
    // but other you may comment/uncomment in any subset
    /*
    bool operator <= ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator <=\n");
      return p * r.q <= r.p * q;
    }
    //*/
    /*
    bool operator > ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator >\n");
      return p * r.q > r.p * q;
    }
    //*/
    //*
    bool operator >= ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator >=\n");
      return p * r.q >= r.p * q;
    }
    //*/
    /*
    bool operator == ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator ==\n");
      return p * r.q == r.p * q;
    }
    //*/
    //*
    bool operator != ( const RationalStub &r ) const {
      fprintf (stderr, "RationalStub::operator !=\n");
      return p * r.q != r.p * q;
    }
    //*/
};

// use the magic from make_comparable.h++
typedef make_comparable::MakeComparable <RationalStub> Rational;

int main () {
  Rational x = Rational (2, 3);
  Rational y = Rational (5, 7);
  printf ("is 2/3 < 5/7? %s\n", x < y ? "yes" : "no");
  printf ("is 2/3 <= 5/7? %s\n", x <= y ? "yes" : "no");
  printf ("is 2/3 > 5/7? %s\n", x > y ? "yes" : "no");
  printf ("is 2/3 >= 5/7? %s\n", x >= y ? "yes" : "no");
  printf ("is 2/3 == 5/7? %s\n", x == y ? "yes" : "no");
  printf ("is 2/3 != 5/7? %s\n", x != y ? "yes" : "no");
  printf ("What about vice versa?\n");
  printf ("is 5/7 < 2/3? %s\n", y < x ? "yes" : "no");
  printf ("is 5/7 <= 2/3? %s\n", y <= x ? "yes" : "no");
  printf ("is 5/7 > 2/3? %s\n", y > x ? "yes" : "no");
  printf ("is 5/7 >= 2/3? %s\n", y >= x ? "yes" : "no");
  printf ("is 5/7 == 2/3? %s\n", y == x ? "yes" : "no");
  printf ("is 5/7 != 2/3? %s\n", y != x ? "yes" : "no");
  return 0;
}

