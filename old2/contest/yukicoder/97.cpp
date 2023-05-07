#include "math/mint.hpp"
#include "unordered_set.hpp"

unsigned xor128_x = 123456789;
unsigned xor128_y = 362436069;
unsigned xor128_z = 521288629;
unsigned xor128_w = 88675123;

unsigned xor128() {
  unsigned t = xor128_x ^ (xor128_x << 11);
  xor128_x = xor128_y;
  xor128_y = xor128_z;
  xor128_z = xor128_w;
  return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}

Vector<int> generateA(int n) {
  Vector<int> res;
  for (int i = 0; i < n; ++i) {
    res.emplace_back(xor128() % 100003);
  }
  return res;
}

int main() {
  int n(in), q(in);
  Vector<int> a = generateA(n);
  UnorderedSet<int> s(a.begin(), a.end());
  const int MOD = 100003;
  Mint::setMod(MOD);
  int cnt = 0;
  for (int i = 0; i < q; ++i) {
    int64_t k(in);
    if (k == 0) {
      cout << 0 << endl;
    } else if (n < 1000) {
      int64_t res = 0;
      for (int j : a) {
        chmax(res, j * k % MOD);
      }
      cout << res << endl;
    } else {
      for (Mint i = MOD - 1;; --i) {
        ++cnt;
        if (s.contains(int(i / k))) {
          cout << i << endl;
          break;
        }
      }
    }
  }
  cerr << cnt << endl;
}
