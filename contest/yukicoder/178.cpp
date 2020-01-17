#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> c(n);
  for (int i = 0; i < n; ++i) {
    int a(in), b(in);
    c[i] = a + 4 * b;
  }
  if (c.any_of([&](int64_t i) { return (c[0] - i) % 2; })) {
    cout << -1 << endl;
  } else {
    cout << (c.max() * n - c.accumulate()) / 2 << endl;
  }
}
