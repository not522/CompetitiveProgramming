#include "container/union_find.hpp"
#include "math.hpp"

int main() {
  int n(in);
  Vector<int> x(n), y(n);
  read(x, y);
  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) <= 100) {
        uf.unite(i, j);
      }
    }
  }
  double res = (n ? 2 : 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (uf.equal(i, j)) {
        chmax(res, hypot(x[i] - x[j], y[i] - y[j]) + 2);
      }
    }
  }
  cout << res << endl;
}
