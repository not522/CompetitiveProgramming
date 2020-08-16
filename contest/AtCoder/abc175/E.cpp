#include "vector.hpp"

int main() {
  int r(in), c(in), k(in);
  auto bd = Vector<int64_t>(r + 1, c + 1);
  for (int i = 0; i < k; ++i) {
    int a(in), b(in), v(in);
    bd[a][b] = v;
  }
  auto dp = Vector<int64_t> dp = makeVector(r + 1, c + 1, 4);
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      for (int a = 0; a <= 3; ++a) {
        chmax(dp[i][j][0], dp[i - 1][j][a]);
        chmax(dp[i][j][a], dp[i][j - 1][a]);
        chmax(dp[i][j][1], dp[i - 1][j][a] + bd[i][j]);
        if (a < 3) {
          chmax(dp[i][j][a + 1], dp[i][j - 1][a] + bd[i][j]);
        }
      }
    }
  }
  cout << dp.back().back().max() << endl;
}
