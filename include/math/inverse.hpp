#pragma once
#include "template.hpp"

class Inverse {
private:
  long long mod;
  vector<long long> inv;
  
public:
  Inverse() {}
  
  Inverse(long long mod, long long n = 1000000) : mod(mod), inv(n, 1) {for (int i = 2; i < n; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;}
  
  long long operator()(long long a) const {
    if (a < (int)inv.size()) return inv[a];
    long long b = mod, x = 1, y = 0;
    while (b) {
      long long t = a / b;
      swap(a -= t * b, b);
      swap(x -= t * y, y);
    }
    return (x %= mod) < 0 ? x + mod : x;
  }
};
