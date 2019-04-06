#include "cumulative_sum_1D.hpp"

int main() {
  int n(in), m(in), t = 0;
  CumulativeSum1D<int> sum(m);
  for (int i = 0; i < n; ++i) {
    int l(in), r(in), s(in);
    sum.add(l - 1, r, s);
    t += s;
  }
  int res = 0;
  for (int i = 0; i < m; ++i) {
    res = max(res, t - sum.value(i));
  }
  cout << res << endl;
}
