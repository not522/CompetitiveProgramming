#pragma once
#include "template.hpp"

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
    for (int i = 1; i <= n; ++i) res *= i;
    for (int i = 1; i <= m; ++i) res /= i;
    for (int i = 1; i <= n - m; ++i) res /= i;
    return res;
  }

  T repetition(int n, int r) {
    return combination(n + r - 1, r);
  }
};
