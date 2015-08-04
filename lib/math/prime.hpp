#pragma once
#include "template.hpp"

class Prime {
private:
  vector<long long> div;
  
public:
  Prime(long long n = 0) {
    for (long long i = 0; i <= n; ++i) div.emplace_back(i);
    for (long long i = 2; i <= n / i; ++i) if (div[i] == i) {
      for (long long j = i * i; j <= n; j += i) div[j] = i;
    }
  }
  
  bool isPrime(long long n) const {
    if (n <= 1) return false;
    if (n < (long long)div.size()) return div[n] == n;
    for (long long i = 2; i <= n / i; ++i) if (n % i == 0) return false;
    return true;
  }
  
  vector<long long> factor(long long n) const {
    vector<long long> res;
    for (long long i = 2; i <= n / i && n >= (long long)div.size(); ++i) {
      while (n % i == 0) {
        res.emplace_back(i);
        n /= i;
      }
    }
    if (n >= max((long long)div.size(), 2ll)) {
      res.emplace_back(n);
    } else {
      while (n > 1) {
        res.emplace_back(div[n]);
        n /= div[n];
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
  
  vector<long long> primeFactor(long long n) const {
    vector<long long> res;
    for (long long i = 2; i <= n / i && n >= (long long)div.size(); ++i) {
      if (n % i) continue;
      res.emplace_back(i);
      while (n % i == 0) n /= i;
    }
    if (n >= max((long long)div.size(), 2ll)) {
      res.emplace_back(n);
    } else {
      while (n > 1) {
        long long d = div[n];
        res.emplace_back(d);
        while (n % d == 0) n /= d;
      }
    }
    sort(res.begin(), res.end());
    return res;
  }

  vector<long long> divisor(long long n) const {
    vector<long long> res;
    for (long long i = 1; i <= n / i; ++i) {
      if (n % i == 0) {
        res.emplace_back(i);
        if (i != n / i) res.emplace_back(n / i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
