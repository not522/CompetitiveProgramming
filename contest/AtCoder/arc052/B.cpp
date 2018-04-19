#include "cumulative_sum_1D.hpp"
#include "math/basic.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  CumulativeSum1D<double> sum(20000);
  for (int i = 0; i < n; ++i) {
    double x, r, h;
    cin >> x >> r >> h;
    for (int j = 0; j < h; ++j) {
      double a = (h - j) / h, b = (h - j - 1) / h;
      double va = square(r * a) * pi() * h * a / 3;
      double vb = square(r * b) * pi() * h * b / 3;
      sum.add(x + j, va - vb);
    }
  }
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << sum.sum(a, b) << endl;
  }
}
