#pragma once
#include "vector.hpp"

template <typename T> bool nim(const Vector<T> &v) {
  return v.accumulate(T(0), std::bit_xor<T>());
}
