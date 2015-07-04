#pragma once
#include "template.hpp"

template<typename T> class Ordered {
public:
  bool operator!=(const T& v) const {
    return !(*this == v);
  }

  bool operator>(const T& v) const {
    return v < *this;
  }

  bool operator<=(const T& v) const {
    return !(v < *this);
  }

  bool operator>=(const T& v) const {
    return !(*this < v);
  }
};
