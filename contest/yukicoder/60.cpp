#include "cumulative_sum_2D.hpp"

int main() {
  int n(in), k(in);
  Vector<int> x(n), y(n), hp(n);
  read(x, y, hp);
  CumulativeSum2D<int> sum(1501, 1501);
  for (int i = 0; i < k; ++i) {
    int ax(in), ay(in), w(in), h(in), d(in);
    sum.add(ay + 500, ax + 500, ay + h + 501, ax + w + 501, d);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += max(0, hp[i] - sum.value(y[i] + 500, x[i] + 500));
  }
  cout << res << endl;
}
