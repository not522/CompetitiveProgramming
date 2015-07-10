#include "cumulative_sum_1D.hpp"

int main() {
  int n;
  cin >> n;
  CumulativeSum1D<int, true> sum(1000001);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    sum.add(a, b + 1, 1);
  }
  int res = 0;
  for (int i = 0; i <= 1000000; ++i) res = max(res, sum.value(i));
  cout << res << endl;
}
