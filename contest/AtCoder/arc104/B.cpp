#include "cumulative_sum_1D.hpp"
#include "string.hpp"

int main() {
  int n(in);
  String s(in);
  CumulativeSum1D<int> sum_a(n), sum_t(n), sum_c(n), sum_g(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      sum_a.add(i, 1);
    }
    if (s[i] == 'T') {
      sum_t.add(i, 1);
    }
    if (s[i] == 'C') {
      sum_c.add(i, 1);
    }
    if (s[i] == 'G') {
      sum_g.add(i, 1);
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j <= n; ++j) {
      if (sum_a.sum(i, i + j) == sum_t.sum(i, i + j) &&
          sum_c.sum(i, i + j) == sum_g.sum(i, i + j)) {
        ++res;
      }
    }
  }
  cout << res << endl;
}
