#include "math/mint.hpp"

int main() {
  string s;
  cin >> s;
  vector<vector<Mint>> dp(s.size() + 1, vector<Mint>(4));
  dp[0][0] = 1;
  for (int i = 0; i < int(s.size()); ++i) {
    for (int j = 0; j < 4; ++j) dp[i + 1][j] = (s[i] == '?' ? 3 : 1) * dp[i][j];
    if (isalpha(s[i])) {
      dp[i + 1][s[i] - 'A' + 1] += dp[i][s[i] - 'A'];
    } else {
      for (int j = 0; j < 3; ++j) dp[i + 1][j + 1] += dp[i][j];
    }
  }
  cout << dp.back().back() << endl;
}
