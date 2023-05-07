#include "container/union_find.hpp"

int main() {
  int t(in);
  for (int _ = 0; _ < t; ++_) {
    int n(in), m(in);
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      int a(in), b(in);
      uf.unite(a - 1, b - 1);
    }
    if (n % 2) {
      if (n % 4 == 1) {
        if (m % 2) {
          cout << "First" << endl;
        } else {
          cout << "Second" << endl;
        }
      } else {
        if (m % 2) {
          cout << "Second" << endl;
        } else {
          cout << "First" << endl;
        }
      }
    } else {
      if ((n % 4 == 0 && m % 2 == 1) || (n % 4 == 2 && m % 2 == 0)) {
        if (uf.size(0) % 2 && uf.size(n - 1) % 2) {
          cout << "Second" << endl;
        } else {
          cout << "First" << endl;
        }
      } else {
        if (uf.size(0) % 2 == 0 && uf.size(n - 1) % 2 == 0) {
          cout << "Second" << endl;
        } else {
          cout << "First" << endl;
        }
      }
    }
  }
}
