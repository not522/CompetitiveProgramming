#include "math/mint.hpp"

int main() {
  int64_t n(in), m(in);
  int64_t max_i = 0;
  for (int64_t i = 1; i <= n; ++i) {
    if (m - i * (i + 1) / 2 >= 0) {
      max_i = i;
    }
  }
  auto dp = Vector<Mint>::makeVector(max_i + 1, m + 1);
  dp[0][0] = 1;
  for (int64_t i = 1; i <= max_i; ++i) {
    for (int64_t j = 0; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - i * (i + 1) / 2 >= 0) {
        dp[i][j] += dp[i][j - i * (i + 1) / 2];
      }
    }
  }
  Mint res = 0;
  for (int64_t i = 0; i < n; ++i) {
    int64_t mm = m - i * (i + 1) / 2;
    if (mm < 0) {
      break;
    }
    auto sum = dp[min(n - i - 1, max_i)];
    for (int j = n; j <= m; ++j) {
      sum[j] += sum[j - n];
    }
    for (int j = 0; j <= mm; ++j) {
      res += dp[i][j] * sum[mm - j];
    }
  }
  cout << res << endl;
}
