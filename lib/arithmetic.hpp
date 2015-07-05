#pragma once
#include "template.hpp"

namespace arithmetic {
  template<typename T> class Addition {
  public:
    T operator+(const T& v) const {
      T res(static_cast<const T&>(*this));
      return res += v;
    }
  };

  template<typename T> class Subtraction {
  public:
    T operator-(const T& v) const {
      T res(static_cast<const T&>(*this));
      return res -= v;
    }
  };

  template<typename T> class Multiplication {
  public:
    T operator*(const T& v) const {
      T res(static_cast<const T&>(*this));
      return res *= v;
    }
  };

  template<typename T> class Division {
  public:
    T operator/(const T& v) const {
      T res(static_cast<const T&>(*this));
      return res /= v;
    }
  };
}

template<typename T> class IndivisibleArithmetic : public arithmetic::Addition<T>, public arithmetic::Subtraction<T>, public arithmetic::Multiplication<T> {};

template<typename T> class Arithmetic : public IndivisibleArithmetic<T>, public arithmetic::Division<T> {};
