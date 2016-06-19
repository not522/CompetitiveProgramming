#include "adjacent_loop.hpp"
#include "vector.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h), t, u;
  cin >> s;
  t = s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      bool black = true;
      for (auto k : AdjacentLoop<9>(i, j, h, w)) {
        if (s[k.first][k.second] == '.') {
          black = false;
        }
      }
      if (!black) {
        t[i][j] = '.';
      }
    }
  }
  u = t;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      bool black = false;
      for (auto k : AdjacentLoop<9>(i, j, h, w)) {
        if (t[k.first][k.second] == '#') {
          black = true;
        }
      }
      if (black) {
        u[i][j] = '#';
      }
    }
  }
  if (s == u) {
    cout << "possible" << endl;
    cout << t;
  } else {
    cout << "impossible" << endl;
  }
}
