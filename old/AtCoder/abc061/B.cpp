#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> c(n);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in);
    ++c[a - 1];
    ++c[b - 1];
  }
  c.output();
}
