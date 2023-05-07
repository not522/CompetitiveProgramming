#include "container/fix_size_set.hpp"
#include "math/mint.hpp"

auto makeUsed(const Vector<Vector<int>> &x, const Bitset64 &bit, int t) {
  auto res = Vector<bool>::makeVector(5, 5);
  int i = 0;
  for (int a = 0; a < 5; ++a) {
    for (int b = 0; b < 5; ++b) {
      if (x[a][b]) {
        if (x[a][b] < t) {
          res[a][b] = true;
        }
      } else {
        if (bit.contains(i)) {
          res[a][b] = true;
        }
        ++i;
      }
    }
  }
  return res;
}

int main() {
  auto x = Vector<int>::makeVector(in, 5, 5);
  int n = x.transform([](const auto &v) { return v.count(0); }).accumulate();
  int k = 0;
  Vector<Mint> dp(1 << n);
  dp[0] = 1;
  auto bits = Vector<int>::makeVector(5, 5);
  int bit = 1;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (x[i][j] == 0) {
        bits[i][j] = bit;
        bit <<= 1;
      }
    }
  }
  for (int i = 1; i <= 25; ++i) {
    bool unset = x.none_of([&](const Vector<int> &v) { return v.contains(i); });
    for (auto bit : fixSizeSet(n, k)) {
      if (dp[bit] == 0) {
        continue;
      }
      auto used = makeUsed(x, bit, i);
      for (int a = 0; a < 5; ++a) {
        for (int b = 0; b < 5; ++b) {
          if (unset) {
            if (used[a][b] || x[a][b]) {
              continue;
            }
            if (0 < a && a < 4 && used[a - 1][b] != used[a + 1][b]) {
              continue;
            }
            if (0 < b && b < 4 && used[a][b - 1] != used[a][b + 1]) {
              continue;
            }
            dp[bit | bits[a][b]] += dp[bit];
          } else {
            if (x[a][b] == i) {
              if (0 < a && a < 4 && used[a - 1][b] != used[a + 1][b]) {
                dp[bit] = 0;
              }
              if (0 < b && b < 4 && used[a][b - 1] != used[a][b + 1]) {
                dp[bit] = 0;
              }
            }
          }
        }
      }
    }
    if (unset) {
      ++k;
    }
  }
  cout << dp.back() << endl;
}
