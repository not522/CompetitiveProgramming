#include "vector.hpp"

void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    ++m[l];
  }
  vector<int> v = {0, 0, 0};
  for (auto i : m) v.emplace_back(i.second);
  rsort(v);
  int res = 0;
  while (v[2] > 0) {
    for (int i = 0; i < 3; ++i) --v[i];
    rsort(v);
    ++res;
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
