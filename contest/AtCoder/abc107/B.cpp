#include "template.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  cin >> a;
  set<int> x, y;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        x.emplace(j);
        y.emplace(i);
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    if (!y.count(i)) continue;
    for (int j = 0; j < w; ++j) {
      if (!x.count(j)) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}
