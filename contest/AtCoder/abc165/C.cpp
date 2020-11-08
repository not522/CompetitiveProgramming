#include "vector.hpp"

void getA(int n, int m, int i, Vector<int> &x, Vector<Vector<int>> &res) {
  if (i == n) {
    res.emplace_back(x);
  } else if (i == 0) {
    for (int j = 1; j <= m; ++j) {
      x.emplace_back(j);
      getA(n, m, i + 1, x, res);
      x.pop_back();
    }
  } else {
    for (int j = x.back(); j <= m; ++j) {
      x.emplace_back(j);
      getA(n, m, i + 1, x, res);
      x.pop_back();
    }
  }
}

int main() {
  int n(in), m(in), q(in), res = 0;
  Vector<int> a(q), b(q), c(q), d(q), x;
  Vector<Vector<int>> y;
  read(a, b, c, d);
  --a;
  --b;
  getA(n, m, 0, x, y);
  for (const auto &z : y) {
    int r = 0;
    for (int i = 0; i < q; ++i) {
      if (z[b[i]] - z[a[i]] == c[i]) {
        r += d[i];
      }
    }
    chmax(res, r);
  }
  cout << res << endl;
}
