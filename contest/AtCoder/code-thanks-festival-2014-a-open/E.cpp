#include "cumulative_sum_2D.hpp"
#include "vector.hpp"

int main() {
  int r, c, m, n;
  cin >> r >> c >> m >> n;
  vector<int> ra(n), rb(n), ca(n), cb(n), res;
  for (int i = 0; i < n; ++i) cin >> ra[i] >> rb[i] >> ca[i] >> cb[i];
  CumulativeSum2D<int, true> sum(r, c), sum0(r, c), sum1(r, c);
  for (int i = 0; i < n; ++i) sum.add(ra[i] - 1, ca[i] - 1, rb[i], cb[i], 1);
  for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
    if (sum.value(i, j) % 4 == 0) sum0.add(i, j, 1);
    if (sum.value(i, j) % 4 == 1) sum1.add(i, j, 1);
  }
  int a = sum0.sum(0, 0, r, c);
  for (int i = 0; i < n; ++i) {
    if (a - sum0.sum(ra[i] - 1, ca[i] - 1, rb[i], cb[i]) + sum1.sum(ra[i] - 1, ca[i] - 1, rb[i], cb[i]) == m) {
      res.emplace_back(i + 1);
    }
  }
  cout << res;
}
