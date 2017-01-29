#include "minmax.hpp"

int main() {
  int w, n, k;
  cin >> w >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector<vector<int>> dp(k + 1, vector<int>(w + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = k; j > 0; --j) {
      for (int l = 0; l + a[i] <= w; ++l) chmax(dp[j][l + a[i]], dp[j - 1][l] + b[i]);
    }
  }
  int res = 0;
  for (int i = 0; i <= k; ++i) chmax(res, dp[i].back());
  cout << res << endl;
}
