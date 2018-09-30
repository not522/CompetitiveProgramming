#include "adjacent_loop.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') continue;
      bool ok = false;
      for (auto p : AdjacentLoop<4>(i, j, h, w)) {
        if (s[p.first][p.second] == '#') ok = true;
      }
      if (!ok) {
        cout << false << endl;
        return 0;
      }
    }
  }
  cout << true << endl;
}
