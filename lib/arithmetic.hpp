#pragma once
#include "template.hpp"

template<typename T> class Arithmetic {
public:
  T operator+(const T& v) const {
    T res(static_cast<const T&>(*this));
    res += v;
    return res;
  }
  
  T operator-(const T& v) const {
    T res(static_cast<const T&>(*this));
    res -= v;
    return res;
  }
  
  T operator*(const T& v) const {
    T res(static_cast<const T&>(*this));
    res *= v;
    return res;
  }
  
  T operator/(const T& v) const {
    T res(static_cast<const T&>(*this));
    res /= v;
    return res;
  }
};
