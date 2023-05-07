#pragma once
#include "template.hpp"

template <typename T> class Bitwise {
public:
  T operator&(const T &v) const {
    return T(static_cast<const T &>(*this)) &= v;
  }

  T operator|(const T &v) const {
    return T(static_cast<const T &>(*this)) |= v;
  }

  T operator^(const T &v) const {
    return T(static_cast<const T &>(*this)) ^= v;
  }
};
