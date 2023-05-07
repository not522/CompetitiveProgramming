#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  int q(in);
  Vector<int> b(q), c(q);
  read(b, c);
  Map<int, int> m;
  int64_t res = 0;
  for (int k : a) {
    ++m[k];
    res += k;
  }
  for (int i = 0; i < q; ++i) {
    res += (c[i] - b[i]) * m[b[i]];
    m[c[i]] += m[b[i]];
    m[b[i]] = 0;
    cout << res << endl;
  }
}
