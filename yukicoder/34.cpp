#include "template.hpp"

int main() {
  int n, v, sx, sy, gx, gy;
  cin >> n >> v >> sx >> sy >> gx >> gy;
  --sx, --sy, --gx, --gy;
  vector<vector<int>> l(n, vector<int>(n));
  for (auto& i : l) {
    for (int& j : i) cin >> j;
  }
  vector<vector<int>> u(n, vector<int>(n)), w(n, vector<int>(n));
  u[sy][sx] = v;
  queue<pair<int, int>> que;
  que.push(make_pair(sy, sx));
  const int dy[] = {0, -1, 0, 1};
  const int dx[] = {1, 0, -1, 0};
  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    int y = now.first, x = now.second;
    for (int k = 0; k < 4; ++k) {
      int yy = y + dy[k], xx = x + dx[k];
      if (yy < 0 || n <= yy || xx < 0 || n <= xx) continue;
      if (u[yy][xx] >= u[y][x] - l[yy][xx]) continue;
      u[yy][xx] = u[y][x] - l[yy][xx];
      w[yy][xx] = w[y][x] + 1;
      que.push(make_pair(yy, xx));
      if (yy == gy && xx == gx) {
        cout << w[yy][xx] << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
