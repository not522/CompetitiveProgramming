#include "template.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  cin >> a;
  vector<tuple<int, int, int, int>> res;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      if (a[i][j] % 2) {
        res.emplace_back(i + 1, j + 1, i + 1, j + 2);
        ++a[i][j + 1];
      }
    }
    if (i < h - 1 && a[i].back() % 2) {
      res.emplace_back(i + 1, w, i + 2, w);
      ++a[i + 1][w - 1];
    }
  }
  cout << res.size() << endl;
  for (auto i : res) cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << " " << get<3>(i) << endl;
}
