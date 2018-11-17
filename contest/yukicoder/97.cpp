#include "math/mint.hpp"

unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;

unsigned xor128() {
  unsigned t = xor128_x ^ (xor128_x << 11);
  xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
  return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}

void generateA(int N, int A[]) {
  for(int i = 0; i < N; ++ i) A[i] = xor128() % 100003;
}

int main() {
  int n, q;
  cin >> n >> q;
  int a[n];
  generateA(n, a);
  unordered_set<int> s;
  for (int i : a) s.insert(i);
  const int MOD = 100003;
  Mint::setMod(MOD);
  for (int i = 0; i < q; ++i) {
    int64_t k;
    cin >> k;
    if (k == 0) {
      cout << 0 << endl;
    } else if (n < 1000) {
      int64_t res = 0;
      for (int j : a) res = max(res, j * k % MOD);
      cout << res << endl;
    } else {
      for (Mint i = MOD - 1; ; --i) {
        if (s.count(int64_t(i / k))) {
          cout << i << endl;
          break;
        }
      }
    }
  }
}
