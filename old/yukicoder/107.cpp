#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int& i : d) cin >> i;
  vector<pair<int, int>> dp(1 << n, make_pair(-1, 0));
  dp[0] = make_pair(100, 100);
  for (int bit = 0; bit < (1 << n); ++bit) {
    if (dp[bit].second == 0) continue;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) continue;
      int next = bit ^ (1 << i);
      if (d[i] > 0) {
        dp[next].first = dp[bit].first;
        dp[next].second = max(dp[next].second, min(dp[bit].second + d[i], dp[bit].first));
      } else {
        dp[next].first = dp[bit].first + 100;
        dp[next].second = max(dp[next].second, dp[bit].second + d[i]);
      }
    }
  }
  cout << dp[(1 << n) - 1].second << endl;
}
