#pragma once
#include "template.hpp"

template<typename T> class Bitwise {
public:
  T operator&(const T& v) const {
    T res(static_cast<const T&>(*this));
    return res &= v;
  }

  T operator|(const T& v) const {
    T res(static_cast<const T&>(*this));
    return res |= v;
  }

  T operator^(const T& v) const {
    T res(static_cast<const T&>(*this));
    return res ^= v;
  }
};
