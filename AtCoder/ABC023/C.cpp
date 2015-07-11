#include "template.hpp"

int main() {
  int r, c, k, n;
  cin >> r >> c >> k >> n;
  vector<int> v(r, 0), u(c, 0);
  set<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++v[a], ++u[b];
    s.insert(make_pair(a, b));
  }
  long long res = 0;
  for (auto p : s) {
    if (v[p.first] + u[p.second] - 1 == k) ++res;
    if (v[p.first] + u[p.second] == k) --res;
  }
  sort(v.begin(), v.end());
  sort(u.begin(), u.end());
  for (auto i : v) {
    auto b = equal_range(u.begin(), u.end(), k - i);
    res += b.second - b.first;
  }
  cout << res << endl;
}
