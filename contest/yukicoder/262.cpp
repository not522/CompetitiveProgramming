#include "bit_operation.hpp"

int main() {
  using var = uint64_t;
  pair<var, int> dp[64][64][64];
  for (int i = 0; i < 64; ++i) {
    for (int j = 0; j < 64; ++j) {
      if (i == 0 && j == 0) continue;
      var t = j;
      dp[6][i][j].first = 0;
      for (; t < 64; t += count_bit(t) + i) ++dp[6][i][j].first;
      dp[6][i][j].second = t - 64;
    }
  }
  for (int i = 7; i < 64; ++i) {
    for (int j = 0; j < 64; ++j) {
      for (int k = 0; k < 64; ++k) {
        if (j == 0 && k == 0) continue;
        auto f = dp[i - 1][j][k];
        auto s = dp[i - 1][j + 1][f.second];
        dp[i][j][k] = make_pair(f.first + s.first, s.second);
      }
    }
  }
  var n, m = 1, res = 1;
  cin >> n;
  for (int i = 63; i >= 6; --i) {
    int t = count_bit(m >> 6);
    auto s = dp[i][t][m % 64];
    var l = m + (1ull << i) - m % 64 + s.second;
    if (l > n) continue;
    res += s.first;
    m = l;
  }
  while (m < n) {
    ++res;
    m += count_bit(m);
  }
  if (m == n) cout << res << endl;
  else cout << -1 << endl;
}
