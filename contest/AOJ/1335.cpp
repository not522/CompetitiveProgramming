#include "vector.hpp"

int main() {
  for (int n, k, s; n = in, k = in, s = in, n != 0 || k != 0 || s != 0;) {
    Vector<Vector<int>> dp(k + 1, Vector<int>(s + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = k - 1; j >= 0; --j) {
        for (int a = 0; a + i <= s; ++a) {
          dp[j + 1][a + i] += dp[j][a];
        }
      }
    }
    cout << dp[k][s] << endl;
  }
}
