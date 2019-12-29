#include "adjacent_loop.hpp"
#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  Vector<String> s(h, in);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        continue;
      }
      s[i][j] = '0';
      for (auto k : AdjacentLoop<8>(i, j, h, w)) {
        if (s[k.get<0>()][k.get<1>()] == '#') {
          ++s[i][j];
        }
      }
    }
  }
  s.output();
}
