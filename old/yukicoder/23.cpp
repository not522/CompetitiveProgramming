#include "template.hpp"

int main() {
  int h, a, d;
  cin >> h >> a >> d;
  map<int, double> dp;
  for (int i = 1; i <= h; ++i) dp[i] = min(dp[i - a] + 1, dp[i - d] + 1.5);
  cout << dp[h] << endl;
}
