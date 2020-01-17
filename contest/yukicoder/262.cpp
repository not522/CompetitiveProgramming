#include "bit_operation.hpp"
#include "tuple.hpp"

int main() {
  Tuple<uint64_t, int> dp[64][64][64];
  for (int i = 0; i < 64; ++i) {
    for (int j = 0; j < 64; ++j) {
      if (i == 0 && j == 0) {
        continue;
      }
      uint64_t t = j;
      dp[6][i][j].get<0>() = 0;
      for (; t < 64; t += count_bit(t) + i) {
        ++dp[6][i][j].get<0>();
      }
      dp[6][i][j].get<1>() = t - 64;
    }
  }
  for (int i = 7; i < 64; ++i) {
    for (int j = 0; j < 64; ++j) {
      for (int k = 0; k < 64; ++k) {
        if (j == 0 && k == 0) {
          continue;
        }
        auto f = dp[i - 1][j][k];
        auto s = dp[i - 1][j + 1][f.get<1>()];
        dp[i][j][k] = makeTuple(f.get<0>() + s.get<0>(), s.get<1>());
      }
    }
  }
  uint64_t n(in), m = 1, res = 1;
  for (int i = 63; i >= 6; --i) {
    int t = count_bit(m >> 6);
    auto s = dp[i][t][m % 64];
    uint64_t l = m + (1ull << i) - m % 64 + s.get<1>();
    if (l > n) {
      continue;
    }
    res += s.get<0>();
    m = l;
  }
  while (m < n) {
    ++res;
    m += count_bit(m);
  }
  if (m == n) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
}
