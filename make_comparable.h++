#pragma once


namespace make_comparable {
  template <typename T>
  concept bool ComparableLess = requires ( const T &x, const T &y ) { {x < y} -> bool; };
  template <typename T>
  concept bool ComparableLessEqual = requires ( const T &x, const T &y ) { {x <= y} -> bool; };
  template <typename T>
  concept bool ComparableMore = requires ( const T &x, const T &y ) { {x > y} -> bool; };
  template <typename T>
  concept bool ComparableMoreEqual = requires ( const T &x, const T &y ) { {x >= y} -> bool; };
  template <typename T>
  concept bool ComparableEqual = requires ( const T &x, const T &y ) { {x == y} -> bool; };
  template <typename T>
  concept bool ComparableNotEqual = requires ( const T &x, const T &y ) { {x != y} -> bool; };
}

namespace make_comparable_private {
  template <typename T>
  concept bool ComparableBase = make_comparable::ComparableLess <T>;
  template <typename T>
  concept bool ComparableLessEqualOk = ComparableBase <T> && make_comparable::ComparableLessEqual <T>;
  template <typename T>
  concept bool ComparableMoreOk = ComparableBase <T> && make_comparable::ComparableMore <T>;
  template <typename T>
  concept bool ComparableMoreEqualOk = ComparableBase <T> && make_comparable::ComparableMoreEqual <T>;
  template <typename T>
  concept bool ComparableEqualOk = ComparableBase <T> && make_comparable::ComparableEqual <T>;
  template <typename T>
  concept bool ComparableNotEqualOk = ComparableBase <T> && make_comparable::ComparableNotEqual <T>;
}


// <=
namespace make_comparable_private {
  template <ComparableLessEqualOk T>
  class SkipComparableLessEqual : public T {
    public:
      template <typename ...Args>
      SkipComparableLessEqual ( Args ... args ) : T (args...) {};
  };
  template <ComparableBase T>
  class ForceComparableLessEqual : public T {
    public:
      template <typename ...Args>
      ForceComparableLessEqual ( Args ... args ) : T (args...) {};
      bool operator <= ( const ForceComparableLessEqual <T> &y ) const {
        return !(y < *this);
      }
  };
  template <ComparableLessEqualOk T>
  SkipComparableLessEqual <T> makeComparableLessEqual ( T x );
  template <ComparableBase T>
  ForceComparableLessEqual <T> makeComparableLessEqual ( T x );
  template <typename T>
  using MakeComparableLessEqual = decltype (makeComparableLessEqual (T ()));
}


// >
namespace make_comparable_private {
  template <ComparableMoreOk T>
  class SkipComparableMore : public T {
    public:
      template <typename ...Args>
      SkipComparableMore ( Args ... args ) : T (args...) {};
  };
  template <ComparableBase T>
  class ForceComparableMore : public T {
    public:
      template <typename ...Args>
      ForceComparableMore ( Args ... args ) : T (args...) {};
      bool operator > ( const ForceComparableMore <T> &y ) const {
        return (y < *this);
      }
  };
  template <ComparableMoreOk T>
  SkipComparableMore <T> makeComparableMore ( T x );
  template <ComparableBase T>
  ForceComparableMore <T> makeComparableMore ( T x );
  template <typename T>
  using MakeComparableMore = decltype (makeComparableMore (T ()));
}


// >=
namespace make_comparable_private {
  template <ComparableMoreEqualOk T>
  class SkipComparableMoreEqual : public T {
    public:
      template <typename ...Args>
      SkipComparableMoreEqual ( Args ... args ) : T (args...) {};
  };
  template <ComparableBase T>
  class ForceComparableMoreEqual : public T {
    public:
      template <typename ...Args>
      ForceComparableMoreEqual ( Args ... args ) : T (args...) {};
      bool operator >= ( const ForceComparableMoreEqual <T> &y ) const {
        return !(*this < y);
      }
  };
  template <ComparableMoreEqualOk T>
  SkipComparableMoreEqual <T> makeComparableMoreEqual ( T x );
  template <ComparableBase T>
  ForceComparableMoreEqual <T> makeComparableMoreEqual ( T x );
  template <typename T>
  using MakeComparableMoreEqual = decltype (makeComparableMoreEqual (T ()));
}


// ==
namespace make_comparable_private {
  template <ComparableEqualOk T>
  class SkipComparableEqual : public T {
    public:
      template <typename ...Args>
      SkipComparableEqual ( Args ... args ) : T (args...) {};
  };
  template <ComparableBase T>
  class ForceComparableEqual : public T {
    public:
      template <typename ...Args>
      ForceComparableEqual ( Args ... args ) : T (args...) {};
      bool operator == ( const ForceComparableEqual <T> &y ) const {
        return !(*this < y) && !(y < *this);
      }
  };
  template <ComparableEqualOk T>
  SkipComparableEqual <T> makeComparableEqual ( T x );
  template <ComparableBase T>
  ForceComparableEqual <T> makeComparableEqual ( T x );
  template <typename T>
  using MakeComparableEqual = decltype (makeComparableEqual (T ()));
}


// !=
namespace make_comparable_private {
  template <ComparableNotEqualOk T>
  class SkipComparableNotEqual : public T {
    public:
      template <typename ...Args>
      SkipComparableNotEqual ( Args ... args ) : T (args...) {};
  };
  template <ComparableBase T>
  class ForceComparableNotEqual : public T {
    public:
      template <typename ...Args>
      ForceComparableNotEqual ( Args ... args ) : T (args...) {};
      bool operator != ( const ForceComparableNotEqual <T> &y ) const {
        return *this < y || y < *this;
      }
  };
  template <ComparableNotEqualOk T>
  SkipComparableNotEqual <T> makeComparableNotEqual ( T x );
  template <ComparableBase T>
  ForceComparableNotEqual <T> makeComparableNotEqual ( T x );
  template <typename T>
  using MakeComparableNotEqual = decltype (makeComparableNotEqual (T ()));
}


namespace make_comparable {
  template <typename T>
  using MakeComparable =
    make_comparable_private::MakeComparableLessEqual <
    make_comparable_private::MakeComparableMore <
    make_comparable_private::MakeComparableMoreEqual <
    make_comparable_private::MakeComparableEqual <
    make_comparable_private::MakeComparableNotEqual <
  T>>>>>;
}

