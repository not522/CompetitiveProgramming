#include "vector.hpp"

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
  int sa = accumulate(a), sb = accumulate(b);
  constexpr int INF = numeric_limits<int>::max();
  vector<vector<int>> dp(sa + 1, vector<int>(sb + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = sa - a[i]; j >= 0; --j) {
      for (int k = sb - b[i]; k >= 0; --k) {
        if (dp[j][k] == INF) continue;
        chmin(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
      }
    }
  }
  int res = INF;
  for (int i = 1; ma * i <= sa && mb * i <= sb; ++i) chmin(res, dp[ma * i][mb * i]);
  if (res == INF) res = -1;
  cout << res << endl;
}
