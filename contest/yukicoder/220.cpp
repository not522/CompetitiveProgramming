#include "vector.hpp"

int main() {
  int p;
  cin >> p;
  vector<vector<int64_t>> dp(p + 1, vector<int64_t>(3));
  dp[0][0] = 1;
  for (int i = 0; i < p; ++i) for (int j = 0; j < 3; ++j) dp[i + 1][j] = 3 * accumulate(dp[i]);
  cout << (unsigned int64_t)pow(10, p) - dp.back()[1] - dp.back()[2] - 1 << endl;
}
