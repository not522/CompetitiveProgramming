#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), dp(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (i > 0) dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp.back() << endl;
}
