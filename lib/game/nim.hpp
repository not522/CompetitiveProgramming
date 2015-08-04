#pragma once
#include "template.hpp"

template<typename T> bool nim(const vector<T>& v) {
  return accumulate(v.begin(), v.end(), T(0), bit_xor<T>());
}
