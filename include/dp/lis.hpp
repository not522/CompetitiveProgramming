#pragma once
#include "vector.hpp"

template<typename V, typename T> class LIS {
private:
  const V a;
  const T INF;
  Vector<int> res;

public:
  LIS(const V& a) : a(a), INF(numeric_limits<T>::max()), res(a.size(), INF) {}
  
  T solve() {
    for (auto i : a) *lower_bound(res.begin(), res.end(), i) = i;
    return lower_bound(res.begin(), res.end(), INF) - res.begin();
  }
};
