#pragma once
#include "vector.hpp"

class Prime {
private:
  Vector<int64_t> div;

public:
  Prime(int64_t n = 0) {
    for (int64_t i = 0; i <= n; ++i) {
      div.emplace_back(i);
    }
    for (int64_t i = 2; i <= n / i; ++i) {
      if (div[i] == i) {
        for (int64_t j = i * i; j <= n; j += i) {
          div[j] = i;
        }
      }
    }
  }

  bool isPrime(int64_t n) const {
    if (n <= 1) {
      return false;
    }
    if (n < div.size()) {
      return div[n] == n;
    }
    for (int64_t i = 2; i <= n / i; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  Vector<int64_t> factor(int64_t n) const {
    Vector<int64_t> res;
    for (int64_t i = 2; i <= n / i && n >= div.size(); ++i) {
      while (n % i == 0) {
        res.emplace_back(i);
        n /= i;
      }
    }
    if (n >= max(int(div.size()), 2)) {
      res.emplace_back(n);
    } else {
      while (n > 1) {
        res.emplace_back(div[n]);
        n /= div[n];
      }
    }
    return res.sort();
  }

  Vector<int64_t> primeFactor(int64_t n) const {
    Vector<int64_t> res;
    for (int64_t i = 2; i <= n / i && n >= int64_t(div.size()); ++i) {
      if (n % i) {
        continue;
      }
      res.emplace_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
    if (n >= max(div.size(), 2)) {
      res.emplace_back(n);
    } else {
      while (n > 1) {
        int64_t d = div[n];
        res.emplace_back(d);
        while (n % d == 0) {
          n /= d;
        }
      }
    }
    return res.sort();
  }

  Vector<int64_t> divisor(int64_t n) const {
    Vector<int64_t> res;
    for (int64_t i = 1; i <= n / i; ++i) {
      if (n % i == 0) {
        res.emplace_back(i);
        if (i != n / i) {
          res.emplace_back(n / i);
        }
      }
    }
    sort(res.begin(), res.end());
    return res;
  }

  Vector<int64_t> primes(int64_t n) const {
    Vector<int64_t> res;
    for (int64_t i = 2; i <= n; ++i) {
      if (isPrime(i)) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};

Vector<int64_t> prime_factor(int64_t n) {
  Vector<int64_t> res;
  for (int64_t i = 2; i <= n / i; ++i) {
    if (n % i) {
      continue;
    }
    res.emplace_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n >= 2) {
    res.emplace_back(n);
  }
  return res;
}
