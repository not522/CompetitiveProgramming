#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int64_t> x(n), y(n), z(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
  int64_t res = 0;
  for (int bit = 0; bit < 8; ++bit) {
    vector<int64_t> r;
    for (int i = 0; i < n; ++i) {
      int64_t xx = (bit & 1 ? x[i] : -x[i]);
      int64_t yy = (bit & 2 ? y[i] : -y[i]);
      int64_t zz = (bit & 4 ? z[i] : -z[i]);
      r.emplace_back(xx + yy + zz);
    }
    rsort(r);
    res = max(res, accumulate(r.begin(), r.begin() + m, int64_t(0)));
  }
  cout << res << endl;
}
