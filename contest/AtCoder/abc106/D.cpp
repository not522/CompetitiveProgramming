#include "cumulative_sum_2D.hpp"

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  CumulativeSum2D<int> sum(n, n);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    sum.add(l - 1, r - 1, 1);
  }
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << sum.sum(a - 1, 0, n, b) << endl;
  }
}
