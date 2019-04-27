#include "adjacent_loop.hpp"
#include "math/mint.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  auto a = Vector<int>::makeVector(in, h, w);
  Vector<Vector<Mint>> dp(h, Vector<Mint>(w, 1));
  Vector<Tuple<int, int, int>> k;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      k.emplace_back(a[i][j], i, j);
    }
  }
  k.sort();
  Mint res = 0;
  for (auto i : k) {
    int u, y, x;
    std::tie(u, y, x) = i;
    res += dp[y][x];
    for (auto t : AdjacentLoop<4>(y, x, h, w)) {
      int yy, xx;
      std::tie(yy, xx) = t;
      if (a[yy][xx] > u) {
        dp[yy][xx] += dp[y][x];
      }
    }
  }
  cout << res << endl;
}
