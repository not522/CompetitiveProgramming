#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> a(n), b(n), c(m), d(m);
  read(a, b);
  read(c, d);
  for (int i = 0; i < n; ++i) {
    int r = 0;
    for (int j = 1; j < m; ++j) {
      if (abs(a[i] - c[j]) + abs(b[i] - d[j]) <
          abs(a[i] - c[r]) + abs(b[i] - d[r])) {
        r = j;
      }
    }
    cout << r + 1 << endl;
  }
}
