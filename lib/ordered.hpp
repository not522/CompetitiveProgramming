#pragma once
#include "template.hpp"

template<typename T> class Ordered {
public:
  bool operator==(const T& v) const {
    return !(v < static_cast<const T&>(*this) || static_cast<const T&>(*this) < v);
  }
  
  bool operator!=(const T& v) const {
    return v < static_cast<const T&>(*this) || static_cast<const T&>(*this) < v;
  }

  bool operator>(const T& v) const {
    return v < static_cast<const T&>(*this);
  }

  bool operator<=(const T& v) const {
    return !(v < static_cast<const T&>(*this));
  }

  bool operator>=(const T& v) const {
    return !(static_cast<const T&>(*this) < v);
  }
};
