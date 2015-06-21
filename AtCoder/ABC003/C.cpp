#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) cin >> r[i];
  partial_sort(r.begin(), r.begin() + k, r.end(), greater<int>());
  double res = 0;
  for (int i = k - 1; i >= 0; --i) res = (res + r[i]) / 2;
  cout << fixed << setprecision(15) << res << endl;
}
