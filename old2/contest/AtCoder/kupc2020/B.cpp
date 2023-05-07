#include "math/mint.hpp"
#include "vector.hpp"

int main() {
  int n(in), k(in);
  auto v = Vector<int>::makeVector(in, n, k);
  for (int i = 0; i < n; ++i) {
    v[i].sort();
  }
  auto dp = Vector<Mint>::makeVector(n, k);
  for (int i = 0; i < k; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x = k;
    for (int j = 0; j < k; ++j) {
      if (v[i][j] <= v[i + 1][0]) {
        dp[i + 1][0] += dp[i][j];
      } else {
        x = j;
        break;
      }
    }
    for (int j = 1; j < k; ++j) {
      dp[i + 1][j] = dp[i + 1][j - 1];
      while (x < k && v[i][x] <= v[i + 1][j]) {
        dp[i + 1][j] += dp[i][x];
        ++x;
      }
    }
  }
  cout << dp.back().accumulate() << endl;
}
