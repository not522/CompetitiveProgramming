#pragma once
#include "template.hpp"

template<typename T> class Ordered {
public:
  template<typename V> bool operator==(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v));
  }
  
  template<typename V> bool operator!=(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v);
  }

  template<typename V> bool operator>(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this);
  }

  template<typename V> bool operator<=(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this));
  }

  template<typename V> bool operator>=(const V& v) const {
    return !(static_cast<const T&>(*this) < static_cast<T>(v));
  }
};
