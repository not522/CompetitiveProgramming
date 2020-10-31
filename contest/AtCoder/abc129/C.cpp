#include "math/mint.hpp"
#include "unordered_set.hpp"

int main() {
  int n(in), m(in);
  UnorderedSet<int> a(m, in);
  Vector<Mint> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (a.contains(i)) {
      continue;
    }
    dp[i] += dp[i - 1];
    if (2 <= i) {
      dp[i] += dp[i - 2];
    }
  }
  cout << dp.back() << endl;
}
