#include "adjacent_loop.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      s[i][j] = '0';
      for (auto k : AdjacentLoop<8>(i, j, h, w)) {
        if (s[k.first][k.second] == '#') ++s[i][j];
      }
    }
  }
  cout << s;
}
