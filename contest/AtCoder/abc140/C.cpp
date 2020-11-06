#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n), b(n - 1, in);
  a[0] = b[0];
  a[n - 1] = b[n - 2];
  for (int i = 1; i < n - 1; ++i) {
    a[i] = min(b[i - 1], b[i]);
  }
  cout << a.accumulate() << endl;
}
