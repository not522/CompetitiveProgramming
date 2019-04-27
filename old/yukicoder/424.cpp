#include "adjacent_loop.hpp"
#include "vector.hpp"
#include "container/union_find.hpp"

int main() {
  int h, w, sx, sy, gx, gy;
  cin >> h >> w >> sx >> sy >> gx >> gy;
  --sx, --sy, --gx, --gy;
  vector<string> b(h);
  cin >> b;
  UnionFind uf(h * w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (auto k : AdjacentLoop<2>(i, j, h, w)) {
        int ii = k.first, jj = k.second;
        if (abs(b[i][j] - b[ii][jj]) <= 1) uf.unite(i * w + j, ii * w + jj);
      }
      if (j < w - 2 && b[i][j] > b[i][j + 1] && b[i][j] == b[i][j + 2]) uf.unite(i * w + j, i * w + j + 2);
      if (i < h - 2 && b[i][j] > b[i + 1][j] && b[i][j] == b[i + 2][j]) uf.unite(i * w + j, (i + 2) * w + j);
    }
  }
  cout << (uf.equal(sx * w + sy, gx * w + gy) ? "YES" : "NO") << endl;
}
