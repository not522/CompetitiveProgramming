#pragma once
#include "template.hpp"

template <typename T> class Addition {
public:
  template <typename V> T operator+(const V &v) const {
    return T(static_cast<const T &>(*this)) += v;
  }

  T operator++() { return static_cast<T &>(*this) += 1; }
};

template <typename T> class Subtraction {
public:
  template <typename V> T operator-(const V &v) const {
    return T(static_cast<const T &>(*this)) -= v;
  }
};

template <typename T> class Multiplication {
public:
  template <typename V> T operator*(const V &v) const {
    return T(static_cast<const T &>(*this)) *= v;
  }
};

template <typename T> class Division {
public:
  template <typename V> T operator/(const V &v) const {
    return T(static_cast<const T &>(*this)) /= v;
  }
};

template <typename T> class Modulus {
public:
  template <typename V> T operator%(const V &v) const {
    return T(static_cast<const T &>(*this)) %= v;
  }
};

template <typename T>
class IndivisibleArithmetic : public Addition<T>,
                              public Subtraction<T>,
                              public Multiplication<T> {};

template <typename T>
class Arithmetic : public IndivisibleArithmetic<T>, public Division<T> {};
