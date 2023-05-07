#pragma once
#include "arithmetic.hpp"

template <typename T> class Bitwise : public Arithmetic<Bitwise<T>> {
public:
  T val;

  Bitwise() : val(0) {}

  Bitwise(T val) : val(val) {}

  Bitwise &operator+=(const Bitwise &b) {
    val ^= b.val;
    return *this;
  }

  Bitwise &operator-=(const Bitwise &b) { return *this += b; }

  Bitwise &operator*=(const Bitwise &b) {
    val &= b.val;
    return *this;
  }

  Bitwise &operator/=(const Bitwise &b) { return *this = b; }

  bool operator<(const Bitwise &b) { return val < b.val; }

  bool operator>(const Bitwise &b) { return val > b.val; }

  operator T() const { return val; }
};

template <typename T> Bitwise<T> abs(const Bitwise<T> &b) { return b; }
