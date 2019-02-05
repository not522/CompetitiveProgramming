#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<double> t(n), v(n);
  cin >> t >> v;
  constexpr double INF = numeric_limits<double>::max();
  vector<vector<double>> dp(n + 1, vector<double>(101, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= v[i]; ++j) {
      if (dp[i][j] == INF) continue;
      for (int k = 0; k <= v[i]; ++k) {
        if (t[i] < abs(j - k)) continue;
        double vm = min(v[i], (j + k) / 2.0 + t[i] / 2.0);
        dp[i + 1][k] = dp[i][j] + t[i] * vm - square(vm - j) / 2.0 - square(vm - k) / 2.0;
      }
    }
  }
  cout << dp[n][0] << endl;
}
