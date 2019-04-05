#pragma once
#include "vector.hpp"

template<typename V, typename T> class LIS {
private:
  const V a;
  Vector<int> res;

public:
  LIS(const V& a) : a(a), res(a.size(), inf<T>()) {}
  
  T solve() {
    for (auto i : a) *lower_bound(res.begin(), res.end(), i) = i;
    return lower_bound(res.begin(), res.end(), inf<T>()) - res.begin();
  }
};
