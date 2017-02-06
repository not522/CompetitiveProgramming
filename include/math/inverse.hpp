#pragma once
#include "template.hpp"

class Inverse {
private:
  int64_t mod;
  vector<int64_t> inv;
  
public:
  Inverse() {}
  
  Inverse(int64_t mod, int64_t n = 1000000) : mod(mod), inv(n, 1) {for (int i = 2; i < n; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;}
  
  int64_t operator()(int64_t a) const {
    if (a < int(inv.size())) return inv[a];
    int64_t b = mod, x = 1, y = 0;
    while (b) {
      int64_t t = a / b;
      swap(a -= t * b, b);
      swap(x -= t * y, y);
    }
    return (x %= mod) < 0 ? x + mod : x;
  }
};
