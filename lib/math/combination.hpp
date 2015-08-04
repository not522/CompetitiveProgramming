#pragma once
#include "math/basic.hpp"

template<typename T> class Combination {
private:
  vector<vector<T>> comb;
  
public:
  Combination(int n = 0) : comb(n, vector<T>(n, 0)) {
    for (int i = 0; i < n; ++i) comb[i][0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      }
    }
  }

  T combination(int n, int m) {
    if (n < m) return 0;
    if (n < (int)comb.size()) return comb[n][m];
    T res = 1;
    for (int i = 0; i < min(m, n - m); ++i) res = res * (n - i) / (i + 1);
    return res;
  }

  T combination_safety(int n, int m) {
    if (n < m) return 0;
    if (n < (int)comb.size()) return comb[n][m];
    m = min(m, n - m);
    vector<int> a(m), b(m);
    iota(a.begin(), a.end(), n - m + 1);
    iota(b.begin(), b.end(), 1);
    for (auto i : b) {
      for (auto& j : a) {
        auto g = gcd(i, j);
        i /= g;
        j /= g;
        if (i == 1) break;
      }
    }
    return accumulate(a.begin(), a.end(), T(1), multiplies<T>());
  }

  T repetition(int n, int r) {
    return combination(n + r - 1, r);
  }
};
