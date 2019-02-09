#include "vector.hpp"

vector<int64_t> solve(vector<int64_t> a) {
  vector<int64_t> dp(a.size() + 1);
  for (int i = 0; i < int(a.size()); ++i) {
    dp[i + 1] = dp[i];
    for (int j = i - 1; j >= 0 && a[j] < a[j + 1]; --j) {
      int k = 0;
      for (; a[j] < a[j + 1]; ++k) a[j] *= 4;
      dp[i + 1] += 2 * k;
      if (a[j] > 1e15) {
        dp[i + 1] += k * 2 * j;
        break;
      }
    }
  }
  return dp;
}

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  auto dp1 = solve(a);
  reverse(a);
  auto dp2 = solve(a);
  auto res = numeric_limits<int64_t>::max();
  for (int i = 0; i <= n; ++i) chmin(res, dp1[i] + dp2[n - i] + i);
  cout << res << endl;
}
