#include "template.hpp"

int main() {
  int dp[11][101]{};
  dp[0][0] = 1;
  for (int i = 0; i < 10; ++i) {
    for (int j = i; j >= 0; --j) {
      for (int k = 0; k + i <= 100; ++k) {
        dp[j + 1][k + i] += dp[j][k];
      }
    }
  }
  for (int n, s; cin >> n >> s, n != 0 || s != 0;) {
    cout << dp[n][s] << endl;
  }
}
