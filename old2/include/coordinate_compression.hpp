#pragma once
#include "unordered_map.hpp"
#include "vector.hpp"

template <typename T> UnorderedMap<T, int> coordinateCompression(Vector<T> v) {
  v.sort().unique();
  UnorderedMap<T, int> res;
  for (int i = 0; i < v.size(); ++i) {
    res.emplace(v[i], i);
  }
  return res;
}
