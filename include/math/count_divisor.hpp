#pragma once
#include "template.hpp"

vector<int> count_divisor(int n) {
  vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) ++c[j];
  }
  return c;
}
