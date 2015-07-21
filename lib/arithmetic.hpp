#pragma once
#include "template.hpp"

namespace arithmetic {
  template<typename T> class Addition {
  public:
    template<typename V> T operator+(const V& v) const {
      return T(static_cast<const T&>(*this)) += v;
    }
  };

  template<typename T> class Subtraction {
  public:
    template<typename V> T operator-(const V& v) const {
      return T(static_cast<const T&>(*this)) -= v;
    }
  };

  template<typename T> class Multiplication {
  public:
    template<typename V> T operator*(const V& v) const {
      return T(static_cast<const T&>(*this)) *= v;
    }
  };

  template<typename T> class Division {
  public:
    template<typename V> T operator/(const V& v) const {
      return T(static_cast<const T&>(*this)) /= v;
    }
  };

  template<typename T> class Modulus {
  public:
    template<typename V> T operator%(const V& v) const {
      return T(static_cast<const T&>(*this)) %= v;
    }
  };
}

template<typename T> class IndivisibleArithmetic : public arithmetic::Addition<T>, public arithmetic::Subtraction<T>, public arithmetic::Multiplication<T> {};

template<typename T> class Arithmetic : public IndivisibleArithmetic<T>, public arithmetic::Division<T> {};
