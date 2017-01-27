#include "vector.hpp"

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  set<pair<int, int>> v, black;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    black.emplace(a, b);
    for (int i = -2; i <= 0; ++i) {
      for (int j = -2; j <= 0; ++j) {
        v.emplace(a + i, b + j);
      }
    }
  }
  vector<int> res(10);
  for (auto k : v) {
    if (k.first < 1 || h < k.first + 2 || k.second < 1 || w < k.second + 2) continue;
    int c = 0;
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (black.count(make_pair(k.first + i, k.second + j))) ++c;
      }
    }
    ++res[c];
  }
  cout << int64_t(h - 2) * (w - 2) - accumulate(res) << endl;
  for (int i = 1; i < 10; ++i) cout << res[i] << endl;
}
