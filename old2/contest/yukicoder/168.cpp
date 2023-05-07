#include "container/union_find.hpp"
#include "math.hpp"

int main() {
  int n(in);
  Vector<Tuple<int64_t, int64_t>> p(n, in);
  Vector<Tuple<int64_t, int, int>> dis;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      auto nrm =
          norm(p[i].get<0>(), p[i].get<1>(), p[j].get<0>(), p[j].get<1>());
      auto d = sqrt_int(nrm) + (isSquare(nrm) ? 0 : 1);
      dis.emplace_back(d, i, j);
    }
  }
  dis.sort();
  UnionFind uf(n);
  for (const auto &d : dis) {
    uf.unite(d.get<1>(), d.get<2>());
    if (uf.equal(0, n - 1)) {
      cout << ceil<int64_t>(d.get<0>(), 10) * 10 << endl;
      return 0;
    }
  }
}
