#include "template.hpp"

vector<int64_t> dp1, dp2;

int64_t solve(int n, int64_t x) {
  if (x == dp1[n]) return dp2[n];
  if (x == 1) return 0;
  if (x < dp1[n - 1] + 2) return solve(n - 1, x - 1);
  if (x == dp1[n - 1] + 2) return dp2[n - 1] + 1;
  return dp2[n - 1] + solve(n - 1, x - dp1[n - 1] - 2) + 1;
}

int main() {
  int64_t n, x;
  cin >> n >> x;
  dp1.resize(n + 1, 1);
  dp2.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) dp1[i] = 2 * dp1[i - 1] + 3;
  for (int i = 1; i <= n; ++i) dp2[i] = 2 * dp2[i - 1] + 1;
  cout << solve(n, x) << endl;
}
