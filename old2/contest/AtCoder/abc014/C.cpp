#include "cumulative_sum_1D.hpp"

int main() {
  int n(in);
  CumulativeSum1D<int> sum(1000001);
  for (int i = 0; i < n; ++i) {
    int a(in), b(in);
    sum.add(a, b + 1, 1);
  }
  int res = 0;
  for (int i = 0; i <= 1000000; ++i) {
    chmax(res, sum.value(i));
  }
  cout << res << endl;
}
