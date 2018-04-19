#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<double> r(n);
  for (auto& i : r) cin >> i;
  sort(r.rbegin(), r.rend());
  double res = 0;
  for (int i = 0; i < n; ++i) res += (i % 2 ? -1 : 1) * r[i] * r[i] * pi();
  cout << res << endl;
}
