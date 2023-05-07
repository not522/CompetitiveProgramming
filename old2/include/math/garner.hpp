#pragma once
#include "math/mint.hpp"

Mint garner(vector<int64_t> a, vector<int64_t> m) {
  int n = a.size();
  vector<int64_t> coffs(n, 1), constants(n), digs(n);
  for (int i = 0; i < n; ++i) {
    digs[i] = (a[i] - constants[i] + m[i]) * inverse(coffs[i], m[i]) % m[i];
    for (int j = i + 1; j < n; j++) {
      constants[j] = (constants[j] + coffs[j] * digs[i]) % m[j];
      coffs[j] = (coffs[j] * m[i]) % m[j];
    }
  }
  Mint ans = 0, c = 1;
  for (int i = n - 1; i >= 0; --i) {
    c *= m[i];
    ans = ans * m[i] + digs[i];
  }
  return ans;
}
