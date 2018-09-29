#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  map<int, int> a, b;
  a[0] = 0;
  b[0] = 0;
  for (int i = 0; i < n; i += 2) ++a[v[i]];
  for (int i = 1; i < n; i += 2) ++b[v[i]];
  vector<pair<int, int>> aa, bb;
  for (auto i : a) aa.emplace_back(i.second, i.first);
  for (auto i : b) bb.emplace_back(i.second, i.first);
  rsort(aa);
  rsort(bb);
  if (aa[0].second == bb[0].second) {
    int r = max(aa[1].first + bb[0].first, aa[0].first + bb[1].first);
    cout << n - r << endl;
  } else {
    cout << n - aa[0].first - bb[0].first << endl;
  }
}
