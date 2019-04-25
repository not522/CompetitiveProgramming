#include "vector.hpp"

int main() {
  int n(in), res = -inf<int>();
  Vector<int> a(n, in);
  for (int i = 0; i < n; ++i) {
    int m = -inf<int>(), x = -1;
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      int s = 0;
      for (int k = 1; k <= max(i, j) - min(i, j); k += 2) {
        s += a[min(i, j) + k];
      }
      if (m < s) {
        m = s;
        x = j;
      }
    }
    int t = 0;
    for (int k = 0; k <= max(i, x) - min(i, x); k += 2) {
      t += a[min(i, x) + k];
    }
    chmax(res, t);
  }
  cout << res << endl;
}
