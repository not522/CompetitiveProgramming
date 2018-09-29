#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> x(n), y(n), u(n), v(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i) {
    u[i] = x[i] + y[i];
    v[i] = x[i] - y[i];
  }
  int o = 0, e = 0;
  for (int i = 0; i < n; ++i) {
    if (u[i] % 2) ++o;
    else ++e;
  }
  if (o && e) {
    cout << -1 << endl;
    return 0;
  }
  vector<int64_t> t;
  for (int64_t i = 1ll << 31; i; i /= 2) t.emplace_back(i);
  t.emplace_back(1);
  if (o) t.emplace_back(1);
  cout << t.size() << endl;
  for (int i = 0; i < int(t.size()); ++i) cout << t[i] << (i < int(t.size()) - 1 ? ' ' : '\n');
  vector<string> res(n);
  for (int i = 0; i < n; ++i) {
    for (auto j : t) {
      if (u[i] > 0) {
        if (v[i] > 0) res[i] += 'R';
        else res[i] += 'U';
      } else {
        if (v[i] > 0) res[i] += 'D';
        else res[i] += 'L';
      }
      if (u[i] > 0) u[i] -= j;
      else u[i] += j;
      if (v[i] > 0) v[i] -= j;
      else v[i] += j;
    }
  }
  cout << res;
}
