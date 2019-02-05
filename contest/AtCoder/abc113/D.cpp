#include "math/mint.hpp"

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<Mint>> dp(h + 1, vector<Mint>(w));
  dp[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int bit = 0; bit < (1 << (w - 1)); ++bit) {
      bool ok = true;
      for (int k = 0; k < w - 2; ++k) {
        if ((bit >> k & 3) == 3) ok = false;
      }
      if (!ok) continue;
      for (int k = 0; k < w; ++k) {
        if (bit >> k & 1) dp[i + 1][k + 1] += dp[i][k];
        else if ((k > 0) && (bit >> (k - 1) & 1)) dp[i + 1][k - 1] += dp[i][k];
        else dp[i + 1][k] += dp[i][k];
      }
    }
  }
  cout << dp.back()[k - 1] << endl;
}
