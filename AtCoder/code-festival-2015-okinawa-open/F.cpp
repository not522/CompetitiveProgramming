#include "minmax.hpp"
#include "vector.hpp"
#include "container/fix_size_set.hpp"
#include "container/power_set.hpp"
#include "geometry/point.hpp"

int main() {
  int n;
  cin >> n;
  vector<Point> v(n), a(3);
  cin >> v >> a;
  v.resize(n + 1);
  vector<vector<Real>> dp(2 << n, vector<Real>(n + 1, numeric_limits<long double>::max()));
  dp[1 << n][n] = 0;
  for (auto& k : a) {
    v[n] = k;
    for (int s = 1; s <= n; ++s) for (auto bit : FixSizeSet(n + 1, s)) {
      for (auto i : BitIterator(bit)) for (auto j : BitIterator(((2 << n) - 1) ^ bit)) {
        chmin(dp[bit | 1 << j][j], dp[bit][i] + (v[i] - v[j]).abs());
      }
    }
    for (auto bit : PowerSet(n + 1)) dp[bit][n] = min(dp[bit]);
  }
  cout << min(dp[(2 << n) - 1]) << endl;
}
