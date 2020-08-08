#include "adjacent_loop.hpp"
#include "queue.hpp"
#include "vector.hpp"

int main() {
  int n(in), v(in), sx(in), sy(in), gx(in), gy(in);
  --sx, --sy, --gx, --gy;
  auto l = Vector<int>::makeVector(in, n, n);
  Vector<Vector<int>> u(n, Vector<int>(n)), w(n, Vector<int>(n));
  u[sy][sx] = v;
  Queue<Tuple<int, int>> que;
  que.emplace(sy, sx);
  while (!que.empty()) {
    auto now = que.front();
    int y = now.get<0>(), x = now.get<1>();
    for (auto [yy, xx] : AdjacentLoop<4>(y, x, n, n)) {
      if (!chmax(u[yy][xx], u[y][x] - l[yy][xx])) {
        continue;
      }
      w[yy][xx] = w[y][x] + 1;
      que.emplace(yy, xx);
      if (yy == gy && xx == gx) {
        cout << w[yy][xx] << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
