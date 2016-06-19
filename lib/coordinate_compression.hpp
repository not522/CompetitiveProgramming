#pragma once
#include "vector.hpp"

template<typename T> unordered_map<T, int> coordinateCompression(vector<T> v) {
  sort(v);
  unique(v);
  unordered_map<T, int> res;
  for (int i = 0; i < (int)v.size(); ++i) res.emplace(v[i], i);
  return res;
}
