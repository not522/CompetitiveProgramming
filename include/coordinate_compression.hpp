#pragma once
#include "vector.hpp"

template<typename T> unordered_map<T, int> coordinateCompression(vector<T> v) {
  sort(v);
  unique(v);
  unordered_map<T, int> res;
  for (unsigned i = 0; i < v.size(); ++i) res.emplace(v[i], i);
  return res;
}
