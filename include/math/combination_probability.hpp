#pragma once
#include "template.hpp"

class CombinationProbability {
private:
  vector<vector<double>> comb;
  
public:
  CombinationProbability(int n = 0) : comb(n, vector<double>(n, 0)) {
    for (int i = 0; i < n; ++i) comb[i][0] = pow(0.5, i);
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) / 2;
      }
    }
  }

  double combination(int n, int m) {
    if (n < m) return 0;
    if (n < (int)comb.size()) return comb[n][m];
    double res = 1;
    int t = n;
    for (int i = 0; i < min(m, n - m); ++i) {
      res = res * (n - i) / (i + 1);
      while (res > 1) {
        res /= 2;
        --t;
      }
    }
    while (t) {
      res /= 2;
      --t;
    }
    return res;
  }

  double repetition(int n, int r) {
    return combination(n + r - 1, r);
  }
};
