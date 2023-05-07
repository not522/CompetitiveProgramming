#include "vector.hpp"

int main() {
  int an(in), bn(in), m(in);
  Vector<int> a(an, in), b(bn, in), x(m), y(m), c(m);
  read(x, y, c);
  int res = a.min() + b.min();
  for (int i = 0; i < m; ++i) {
    chmin(res, a[x[i] - 1] + b[y[i] - 1] - c[i]);
  }
  cout << res << endl;
}
