#include "math/mint.hpp"

int main() {
  Mint::setMod(998244353);
  int n(in), k(in);
  auto dp = Vector<Mint>::makeVector(n + 1, n + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = n; j >= 0; --j) {
      if (j - 1 >= 0) {
        dp[i][j] += dp[i - 1][j - 1];
      }
      if (2 * j <= n) {
        dp[i][j] += dp[i][2 * j];
      }
    }
  }
  cout << dp[n][k] << endl;
}
