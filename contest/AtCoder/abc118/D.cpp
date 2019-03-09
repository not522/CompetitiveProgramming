#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  Vector<int> a(m, cin);
  int k[]{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  Vector<string> dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j : a) {
      if (i < k[j] || (i != k[j] && dp[i - k[j]] == "")) continue;
      auto v = dp[i - k[j]] + to_string(j);
      if (dp[i].size() < v.size() || (dp[i].size() == v.size() && dp[i] < v)) dp[i] = v;
    }
  }
  cout << dp.back() << endl;
}
