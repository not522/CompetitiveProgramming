#include "vector.hpp"

int main() {
  constexpr int MAX_A = 100000;
  int n;
  cin >> n;
  vector<int64_t> a(n), b(MAX_A + 1);
  cin >> a;
  for (auto i : a) ++b[i];
  vector<vector<int64_t>> dp(MAX_A + 1, vector<int64_t>(2));
  for (int i = 1; i <= MAX_A; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = dp[i - 1][0] + b[i] * i;
  }
  cout << max(dp[MAX_A][0], dp[MAX_A][1]) << endl;
}
