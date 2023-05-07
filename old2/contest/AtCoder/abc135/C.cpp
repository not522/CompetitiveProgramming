#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n + 1, in), b(n, in);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    auto r1 = min(a[i], b[i]);
    auto r2 = min(a[i + 1], b[i] - r1);
    res += r1 + r2;
    a[i + 1] -= r2;
  }
  cout << res << endl;
}
