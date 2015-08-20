#pragma once
#include "math/basic.hpp"

template<typename T> class Combination {
private:
  vector<T> factorial;

public:
  Combination(int n = 0) : factorial(n + 1, 1) {
    for (int i = 1; i <= n; ++i) factorial[i] = factorial[i - 1] * i;
  }

  T partial_permutation(int n, int m) {
    if (n < m) return 0;
    if (n < (int)factorial.size()) return factorial[n] / factorial[n - m];
    T res = 1;
    for (int i = n; i > n - m; --i) res *= i;
    return res;
  }

  T combination(int n, int m) {
    if (n < m) return 0;
    if (n < (int)factorial.size()) return factorial[n] / factorial[m] / factorial[n - m];
    T res = 1;
    for (int i = 0; i < min(m, n - m); ++i) res = res * (n - i) / (i + 1);
    return res;
  }

  T combination_safety(int n, int m) {
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

  T repetition(int n, int m) {
    if (m == 0) return 1;
    return combination(n + m - 1, m);
  }
};
