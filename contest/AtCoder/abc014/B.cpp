#include "vector.hpp"

int main() {
  int n(in), x(in);
  Vector<int> a(n, in);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (x >> i & 1) {
      res += a[i];
    }
  }
  cout << res << endl;
}
