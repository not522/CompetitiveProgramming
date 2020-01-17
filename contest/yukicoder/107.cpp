#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> d(n, in);
  Vector<Tuple<int, int>> dp(1 << n, Tuple<int, int>(-1, 0));
  dp[0] = Tuple<int, int>(100, 100);
  for (int bit = 0; bit < (1 << n); ++bit) {
    if (dp[bit].get<1>() == 0) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        continue;
      }
      int next = bit ^ (1 << i);
      if (d[i] > 0) {
        dp[next].get<0>() = dp[bit].get<0>();
        chmax(dp[next].get<1>(),
              min(dp[bit].get<1>() + d[i], dp[bit].get<0>()));
      } else {
        dp[next].get<0>() = dp[bit].get<0>() + 100;
        chmax(dp[next].get<1>(), dp[bit].get<1>() + d[i]);
      }
    }
  }
  cout << dp[(1 << n) - 1].get<1>() << endl;
}
