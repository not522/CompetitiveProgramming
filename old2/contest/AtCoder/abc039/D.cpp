#include "adjacent_loop.hpp"
#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  Vector<String> s(h, in), t, u;
  t = s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      bool black = true;
      for (auto [ii, jj] : AdjacentLoop<9>(i, j, h, w)) {
        if (s[ii][jj] == '.') {
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
      for (auto [ii, jj] : AdjacentLoop<9>(i, j, h, w)) {
        if (t[ii][jj] == '#') {
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
    t.output();
  } else {
    cout << "impossible" << endl;
  }
}
