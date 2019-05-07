#pragma once
#include "bit_operation.hpp"
#include "vector.hpp"

template <typename T> class SegmentTree {
private:
  const T DEFAULT;
  int n;
  Vector<T> d;

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return DEFAULT;
    }
    if (a <= l && r <= b) {
      return d[k];
    }
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return function(vl, vr);
  }

protected:
  virtual T function(T l, T r) = 0;

public:
  SegmentTree(int n, T def = inf<T>())
      : DEFAULT(def), n(max(2 << most_bit(n - 1), 2)),
        d(2 * this->n - 1, DEFAULT) {}

  void update(int k, T a) {
    k += n - 1;
    d[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = function(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // [a,b)
  T query(int a, int b) { return query(a, b, 0, 0, n); }

  T getValue(int k) { return d[k + n - 1]; }

  int lower_bound(T t) {
    if (d[0] < t) {
      return n;
    }
    int i = 0;
    while (i < n - 1) {
      if (d[2 * i + 1] >= t) {
        i = 2 * i + 1;
      } else {
        i = 2 * i + 2;
      }
    }
    return i - (n - 1);
  }
};
