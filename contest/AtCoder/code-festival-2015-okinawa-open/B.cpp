#include "template.hpp"

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector<vector<int>> dp(n + 1, vector<int>(y + 1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      for (int k = 0; k <= y; ++k) {
        if (dp[j][k] != -1) chmax(dp[j + 1][min(k + b[i], y)], dp[j][k] + a[i] + b[i]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) if (dp[i][y] >= x + y) {
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
}
