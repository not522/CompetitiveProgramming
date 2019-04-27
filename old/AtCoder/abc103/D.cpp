#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  for (int i = 0; i < m; ++i) cin >> p[i].second >> p[i].first;
  sort(p);
  int t = -1, res = 0;
  for (auto i : p) {
    if (t <= i.second) {
      ++res;
      t = i.first;
    }
  }
  cout << res << endl;
}
