#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n, total;
  cin >> n >> total;
  vector<int> a(n);
  cin >> a;
  vector<vector<string>> dp(n, vector<string>(total + 1, " "));
  dp[0][a[0]] = "";
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= total; ++j) {
      if (dp[i - 1][j] == " ") continue;
      if (j + a[i] <= total) chmax(dp[i][j + a[i]], dp[i - 1][j] + "+");
      if (j * a[i] <= total) chmax(dp[i][j * a[i]], dp[i - 1][j] + "*");
    }
  }
  cout << dp.back().back() << endl;
}
