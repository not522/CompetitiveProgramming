#include "vector.hpp"

int main() {
  constexpr int dx[]{1, 0, -1, 0};
  constexpr int dy[]{0, 1, 0, -1};
  int n(in), x = 0, y = 0, d = 0;
  Vector<Vector<int>> res(n, Vector<int>(n));
  for (int i = 1; i <= n * n; ++i) {
    res[y][x] = i;
    x += dx[d];
    y += dy[d];
    if (x + dx[d] < 0 || n <= x + dx[d] || y + dy[d] < 0 || n <= y + dy[d] ||
        res[y + dy[d]][x + dx[d]]) {
      d = (d + 1) % 4;
    }
  }
  for (const auto &r : res) {
    for (int i = 0; i < n; ++i) {
      cout << std::setw(3) << std::setfill('0') << r[i]
           << (i < n - 1 ? " " : "\n");
    }
  }
}
