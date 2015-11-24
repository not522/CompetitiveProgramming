#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> r(n);
  cin >> r;
  vector<array<int, 2>> dp(n);
  dp[0][0] = dp[0][1] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    if (r[i] > r[i - 1]) chmax(dp[i][0], dp[i - 1][1] + 1);
    if (r[i] < r[i - 1]) chmax(dp[i][1], dp[i - 1][0] + 1);
  }
  int res = max(dp.back()[0], dp.back()[1]);
  cout << (res < 3 ? 0 : res) << endl;
}
