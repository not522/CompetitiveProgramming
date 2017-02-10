#pragma once
#include "template.hpp"

template<typename T> class BIT {
private:
  vector<T> v;

public:
  BIT() {}

  BIT(int n) : v(vector<T>(n + 1, 0)) {}

  // [0, i)
  T sum(int i) {return i ? v[i] + sum(i & (i - 1)) : 0;}

  // [a, b)
  T sum(int a, int b) {return sum(b) - sum(a);}

  void add(int i, T x) {for (++i; i < int(v.size()); i += i & -i) v[i] += x;}
};
