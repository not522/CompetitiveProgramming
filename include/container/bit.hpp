#pragma once
#include "template.hpp"

class BIT {
private:
  vector<int> v;

public:
  BIT() {}

  BIT(int n) : v(vector<int>(n + 1, 0)) {}

  // [0, i)
  int sum(int i) {return i ? v[i] + sum(i & (i - 1)) : 0;}

  // [a, b)
  int sum(int a, int b) {return sum(b) - sum(a);}

  void add(int i, int x) {for (++i; i < int(v.size()); i += i & -i) v[i] += x;}
};
