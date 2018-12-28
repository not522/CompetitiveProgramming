#include "cumulative_sum_1D.hpp"
#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  cin >> a;
  CumulativeSum1D<int64_t> sum1(a), sum2(n);
  for (int i = 0; i < n; ++i) sum2.add(i, max(a[i], int64_t(0)));
  int64_t res = 0;
  for (int i = 0; i + k <= n; ++i) {
    chmax(res, max(sum1.sum(i, i + k), int64_t(0)) + sum2.sum(0, n) - sum2.sum(i, i + k));
  }
  cout << res << endl;
}
