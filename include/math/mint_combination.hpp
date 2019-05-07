#pragma once
#include "math/combination.hpp"
#include "math/mint.hpp"

template <> class Combination<Mint> {
private:
  Vector<Mint> factorial, inverse;

public:
  Combination(int n = 0) : factorial(n + 1, 1), inverse(n + 1) {
    for (int i = 1; i <= n; ++i) {
      factorial[i] = factorial[i - 1] * i;
    }
    inverse[n] = Mint(1) / factorial[n];
    for (int i = n; i >= 1; --i) {
      inverse[i - 1] = inverse[i] * i;
    }
  }

  Mint partial_permutation(int n, int m) {
    if (n < m) {
      return 0;
    }
    if (n < int(factorial.size())) {
      return factorial[n] * inverse[n - m];
    }
    Mint res = 1;
    for (int i = n; i > n - m; --i) {
      res *= i;
    }
    return res;
  }

  Mint combination(int n, int m) {
    if (n < m) {
      return 0;
    }
    if (n < factorial.size()) {
      return factorial[n] * inverse[m] * inverse[n - m];
    }
    Mint res = 1;
    for (int i = 0; i < min(m, n - m); ++i) {
      res = res * (n - i) / (i + 1);
    }
    return res;
  }

  Mint repetition(int n, int m) {
    if (m == 0) {
      return 1;
    }
    return combination(n + m - 1, m);
  }
};
