#include "container/power_set.hpp"
#include "container/union_find.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; ++i) {cin >> x[i] >> y[i]; --x[i]; --y[i];}
  int res = 0;
  for (auto bit : PowerSet(n)) {
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) if (bit.in(x[i]) != bit.in(y[i])) uf.unite(x[i], y[i]);
    if (uf.size() == 1) ++res;
  }
  cout << res / 2 << endl;
}
