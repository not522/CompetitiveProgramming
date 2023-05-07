#pragma once
#include "vector.hpp"

template <typename T> class BIT {
private:
  Vector<T> v;

public:
  BIT(int n) : v(Vector<T>(n + 1, 0)) {}

  // [0, i)
  T sum(int i) { return i ? v[i] + sum(i & (i - 1)) : 0; }

  // [a, b)
  T sum(int a, int b) { return sum(b) - sum(a); }

  void add(int i, T x) {
    for (++i; i < v.size(); i += i & -i) {
      v[i] += x;
    }
  }
};
