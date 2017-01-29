#include "adjacent_loop.hpp"
#include "cumulative_sum_2D.hpp"
#include "container/union_find.hpp"

int main() {
  int r, c, rs, cs, rg, cg, n;
  cin >> r >> c >> rs >> cs >> rg >> cg >> n;
  --rs, --cs, --rg, --cg;
  CumulativeSum2D<int, true> sum(r, c);
  for (int i = 0; i < n; ++i) {
    int r, c, h, w;
    cin >> r >> c >> h >> w;
    --r, --c;
    sum.add(r, c, r + h, c + w, 1);
  }
  UnionFind uf(r * c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (!sum.value(i, j)) continue;
      for (auto k : AdjacentLoop<2>(i, j, r, c)) {
        if (!sum.value(k.first, k.second)) continue;
        uf.unite(i * c + j, k.first * c + k.second);
      }
    }
  }
  cout << (uf.equal(rs * c + cs, rg * c + cg) ? "YES" : "NO") << endl;
}
