#include "vector.hpp"

int main() {
  int n(in), ma(in), mb(in);
  Vector<int> a(n), b(n), c(n);
  read(a, b, c);
  int sa = a.accumulate(), sb = b.accumulate();
  Vector<Vector<int>> dp(sa + 1, Vector<int>(sb + 1, inf<int>()));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = sa - a[i]; j >= 0; --j) {
      for (int k = sb - b[i]; k >= 0; --k) {
        if (dp[j][k] == inf<int>()) {
          continue;
        }
        chmin(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
      }
    }
  }
  int res = inf<int>();
  for (int i = 1; ma * i <= sa && mb * i <= sb; ++i) {
    chmin(res, dp[ma * i][mb * i]);
  }
  if (res == inf<int>()) {
    res = -1;
  }
  cout << res << endl;
}
