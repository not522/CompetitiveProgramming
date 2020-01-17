#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> v(n, in);
  Vector<int> dp(n + 1), prv(n + 1, -1);
  dp[1] = v[0];
  for (int i = 1; i < n; ++i) {
    if (dp[i] > dp[i - 1] + v[i]) {
      dp[i + 1] = dp[i];
      prv[i + 1] = i;
    } else {
      dp[i + 1] = dp[i - 1] + v[i];
      prv[i + 1] = i - 1;
    }
  }
  int t = n;
  Vector<int> res;
  while (t > 0) {
    if (prv[t] != t - 1) {
      res.emplace_back(t);
    }
    t = prv[t];
  }
  res.reverse();
  cout << dp.back() << endl;
  res.output(" ");
}
