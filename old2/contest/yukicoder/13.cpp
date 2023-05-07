#include "container/union_find.hpp"
#include "vector.hpp"

int main() {
  setBoolName("possible", "impossible");
  int w(in), h(in);
  auto m = Vector<int>::makeVector(in, h, w);
  UnionFind uf(w * h);
  bool possible = false;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i != h - 1 && m[i][j] == m[i + 1][j]) {
        if (uf.equal(i * w + j, i * w + j + w)) {
          possible = true;
        }
        uf.unite(i * w + j, i * w + j + w);
      }
      if (j != w - 1 && m[i][j] == m[i][j + 1]) {
        if (uf.equal(i * w + j, i * w + j + 1)) {
          possible = true;
        }
        uf.unite(i * w + j, i * w + j + 1);
      }
    }
  }
  cout << possible << endl;
}
