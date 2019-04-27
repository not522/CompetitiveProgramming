#include "vector.hpp"

int main() {
  int64_t n(in), p = -1, res = 0;
  Vector<int> a(n, in);
  a.emplace_back(-1e9);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= a[i + 1]) {
      res += (i - p) * (i - p + 1) / 2;
      p = i;
    }
  }
  cout << res << endl;
}
