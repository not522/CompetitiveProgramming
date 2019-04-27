#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  iota(dp, 0);
  for (int i = 0; i < n; ++i) {
    for (int k : {6, 9}) {
      for (int j = k; i + j <= n; j *= k) chmin(dp[i + j], dp[i] + 1);
    }
  }
  cout << dp.back() << endl;
}
