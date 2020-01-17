#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> b = iota<int>(n), c(n), res;
  for (int i = 0; i < k; ++i) {
    int x(in), y(in);
    (void)y;
    swap(b[x], b[x - 1]);
  }
  Vector<int> a(n, in);
  for (int i = 0; i < n; ++i) {
    c[a[i] - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    int k = -1;
    for (int j = i; j < n; ++j) {
      if (c[i] == b[j]) {
        k = j;
        break;
      }
    }
    for (int j = k; i < j; --j) {
      swap(b[j], b[j - 1]);
      res.emplace_back(j);
    }
  }
  cout << res.size() << endl;
  for (int i : res) {
    cout << i << " " << i + 1 << endl;
  }
}
