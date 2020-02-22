#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in), b(n, in), c(n - 1, in);
  int res = b.accumulate();
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] + 1 == a[i + 1]) {
      res += c[a[i] - 1];
    }
  }
  cout << res << endl;
}
