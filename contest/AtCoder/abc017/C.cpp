#include "cumulative_sum_1D.hpp"

int main() {
  int n, m, t = 0;
  cin >> n >> m;
  CumulativeSum1D<int> sum(m);
  for (int i = 0; i < n; ++i) {
    int l, r, s;
    cin >> l >> r >> s;
    sum.add(l - 1, r, s);
    t += s;
  }
  int res = 0;
  for (int i = 0; i < m; ++i) {
    res = max(res, t - sum.value(i));
  }
  cout << res << endl;
}
