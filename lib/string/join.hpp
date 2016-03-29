#pragma once
#include "string/to_string.hpp"

template<typename T> string join(const vector<T> &v, char delim = ' ') {
  string res;
  for (const auto& s : v) res += delim + to_string(s);
  return res.substr(1);
}
