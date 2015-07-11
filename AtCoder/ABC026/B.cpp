#include "geometry/const.hpp"

int main() {
  int n;
  cin >> n;
  vector<Real> r(n);
  for (auto& i : r) cin >> i;
  sort(r.rbegin(), r.rend());
  Real res = 0;
  for (int i = 0; i < n; ++i) res += (i % 2 ? -1 : 1) * r[i] * r[i] * PI;
  cout << fixed << setprecision(15) << res << endl;
}
