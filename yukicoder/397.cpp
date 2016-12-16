#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    int j = min_element(a.begin() + i, a.end()) - a.begin();
    if (i != j) res.emplace_back(i, j);
    swap(a[i], a[j]);
  }
  cout << res.size() << endl;
  for (auto i : res) cout << i.first << " " << i.second << endl;
  cin >> n;
}
