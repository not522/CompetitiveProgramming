#include "math/mint.hpp"

int main() {
  int t;
  cin >> t;
  vector<int> a(t);
  cin >> a;
  a.resize(400);
  vector<vector<Mint>> dp(400, vector<Mint>(601));
  dp[0][0] = 1;
  Mint res = 0;
  for (int i = 1; i < 400; ++i) {
    for (int j = 0; j <= 600; j += 2) {
      for (int k = 0; k <= a[i - 1]; ++k) {
        dp[i][k + j / 2] += dp[i - 1][j];
      }
    }
    res += dp[i][1];
  }
  cout << res << endl;
}
