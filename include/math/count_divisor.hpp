#pragma once
#include "vector.hpp"

Vector<int> count_divisor(int n) {
  Vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ++c[j];
    }
  }
  return c;
}
