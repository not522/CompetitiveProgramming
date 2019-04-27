#include "adjacent_loop.hpp"
#include "vector.hpp"
#include "container/union_find.hpp"
#include "math/basic.hpp"
#include "string/join.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  cin >> c;
  UnionFind uf(h * w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (auto k : AdjacentLoop<8>(i, j, h, w)) {
        if (c[i][j] == '.' || c[k.first][k.second] == '.') continue;
        uf.unite(i * w + j, k.first * w + k.second);
      }
    }
  }
  vector<int> r(3);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!uf.isRoot(i * w + j)) continue;
      int s = uf.size(i * w + j);
      if (s == 1) continue;
      if (s % 3 == 0u && isSquare(s / 3)) ++r[0];
      else if (s % 11 == 0u && isSquare(s / 11)) ++r[2];
      else ++r[1];
    }
  }
  cout << join(r) << endl;
}
