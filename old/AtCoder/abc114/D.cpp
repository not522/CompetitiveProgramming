#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime(n);
  map<int, int> m;
  for (int i = 1; i <= n; ++i) {
    for (auto p : prime.factor(i)) ++m[p];
  }
  vector<vector<int>> dp(n + 1, vector<int>(76));
  dp[0][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 75; ++j) {
      for (int k = 0; k <= m[i]; ++k) {
        if (j * (k + 1) <= 75) dp[i][j * (k + 1)] += dp[i - 1][j];
      }
    }
  }
  cout << dp.back().back() << endl;
}
