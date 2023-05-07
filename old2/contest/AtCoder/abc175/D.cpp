#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int64_t> p(n, in), c(n, in);
  --p;
  int64_t res = -inf<int64_t>();
  if (k < n) {
    for (int i = 0; i < n; ++i) {
      int ii = i;
      int64_t r = 0;
      for (int j = 0; j < k; ++j) {
        ii = p[ii];
        r += c[ii];
        chmax(res, r);
      }
    }
    cout << res << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    int ii = i, m = 0;
    int64_t r = 0;
    for (int j = 0; j < n; ++j) {
      ii = p[ii];
      r += c[ii];
      chmax(res, r);
      if (i == ii) {
        m = j + 1;
        break;
      }
    }
    r = (k / m - 1) * r;
    for (int j = 0; j < k % m + m; ++j) {
      ii = p[ii];
      r += c[ii];
      chmax(res, r);
    }
  }
  cout << res << endl;
}
