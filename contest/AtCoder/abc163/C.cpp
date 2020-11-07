#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n - 1, in), c(n);
  --a;
  for (int i = n - 2; i >= 0; --i) {
    ++c[a[i]];
  }
  c.output();
}
