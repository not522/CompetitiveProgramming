#pragma once
#include "bit_operation.hpp"

template<typename T> class SegmentTree {
private:
  const T DEFAULT;
  int n;
  vector<T> d;
  
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return DEFAULT;
    if (a <= l && r <= b) return d[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return function(vl, vr);
  }

protected:
  virtual T function(T l, T r) = 0;
  
public:
  SegmentTree(int m, T def = numeric_limits<T>::max()) : DEFAULT(def) , n(2 << least_bit(m - 1)), d(2 * n - 1, DEFAULT) {}

  void update(int k, T a) {
    k += n - 1;
    d[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = function(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // [a,b)
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  T getValue(int k) {
    return d[k + n - 1];
  }
};
