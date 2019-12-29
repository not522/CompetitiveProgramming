#include "container/power_set.hpp"

int main() {
  int n(in), res = -inf<int>();
  Vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      int b(in);
      f[i] |= b << j;
    }
  }
  Vector<Vector<int>> p(n, Vector<int>(11, in));
  for (auto i : powerSet(10)) {
    if (i == 0) {
      continue;
    }
    int r = 0;
    for (int j = 0; j < n; ++j) {
      r += p[j][count_bit(i & f[j])];
    }
    chmax(res, r);
  }
  cout << res << endl;
}
