#include "cumulative_sum_2D.hpp"

int main() {
  int n(in);
  auto d = Vector<int>::makeVector(in, n, n);
  CumulativeSum2D<int> cumulativeSum2D(d);
  Vector<int> res(n * n + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = i + 1; k <= n; ++k) {
        for (int l = j + 1; l <= n; ++l) {
          int area = (k - i) * (l - j);
          res[area] = max(res[area], cumulativeSum2D.sum(i, j, k, l));
        }
      }
    }
  }
  for (int i = 0; i < n * n; ++i) {
    chmax(res[i + 1], res[i]);
  }
  int q(in);
  for (int i = 0; i < q; ++i) {
    cout << res[int(in)] << endl;
  }
}
