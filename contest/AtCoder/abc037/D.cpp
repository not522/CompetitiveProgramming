#include "adjacent_loop.hpp"
#include "vector.hpp"
#include "math/mint.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<Mint>> dp(h, vector<Mint>(w, 1));
  cin >> a;
  vector<tuple<int, int, int>> k;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      k.emplace_back(a[i][j], i, j);
    }
  }
  sort(k);
  Mint res = 0;
  for (auto i : k) {
    int u, y, x;
    tie(u, y, x) = i;
    res += dp[y][x];
    for (auto t : AdjacentLoop<4>(y, x, h, w)) {
      if (a[t.first][t.second] > u) {
        dp[t.first][t.second] += dp[y][x];
      }
    }
  }
  cout << res << endl;
}
