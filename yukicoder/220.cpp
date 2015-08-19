#include "template.hpp"

int main() {
  int p;
  cin >> p;
  vector<vector<long long>> dp(p + 1, vector<long long>(3));
  dp[0][0] = 1;
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < 3; ++j) {
      dp[i + 1][j] = 3 * accumulate(dp[i].begin(), dp[i].end(), 0ll);
    }
  }
  cout << (unsigned long long)pow(10, p) - dp.back()[1] - dp.back()[2] - 1 << endl;
}