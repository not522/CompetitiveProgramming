#pragma once
#include "template.hpp"

template<typename T> string to_string(const T& v) {
  string str;
  for (const auto& i : const_cast<T&>(v)) str += to_string(i) + " ";
  return str.substr(0, max(0, (int)str.size() - 1));
}
