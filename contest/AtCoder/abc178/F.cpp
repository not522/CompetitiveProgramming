#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in), b(n, in), c(n + 1, -1), d(n + 1, -1), res(n);
  for (int i = 0; i < n; ++i) {
    c[a[i]] = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    d[b[i]] = i;
  }
  int m = -n;
  for (int i = 1; i <= n; ++i) {
    if (c[i] == -1 || d[i] == -1) {
      continue;
    }
    chmax(m, c[i] - d[i] + 1);
  }
  for (int i = 0; i < n; ++i) {
    res[(i + m + n) % n] = b[i];
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == res[i]) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
  res.output(" ");
}
