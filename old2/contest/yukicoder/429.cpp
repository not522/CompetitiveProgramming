#include "string.hpp"

int main() {
  int n(in), k(in);
  (void)static_cast<int>(in);
  Vector<int> aa, bb, r;
  auto v = iota<int>(n);
  auto u = iota<int>(n);
  bool q = false;
  for (int i = 0; i < k; ++i) {
    String a(in), b(in);
    if (a == "?") {
      q = true;
    } else if (!q) {
      swap(v[int(a) - 1], v[int(b) - 1]);
    } else {
      swap(u[int(a) - 1], u[int(b) - 1]);
    }
  }
  Vector<int> c(n, in);
  for (int i = 0; i < n; ++i) {
    if (v[u[i]] != c[i] - 1) {
      r.emplace_back(u[i] + 1);
    }
  }
  r.sort();
  cout << r[0] << " " << r[1] << endl;
}
