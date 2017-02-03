#pragma once
#include "template.hpp"

template<typename T> map<typename T::value_type, int> count(const T& t) {
  map<typename T::value_type, int> res;
  for (const auto& i : t) ++res[i];
  return res;
}
