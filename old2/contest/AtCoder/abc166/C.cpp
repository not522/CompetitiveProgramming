#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> h(n, in);
  Vector<bool> good(n, true);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in);
    --a;
    --b;
    if (h[a] <= h[b]) {
      good[a] = false;
    }
    if (h[b] <= h[a]) {
      good[b] = false;
    }
  }
  cout << good.count_if([](bool b) { return b ? 1 : 0; }) << endl;
}
