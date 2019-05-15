#include "vector.hpp"

int n, a, b, c;
Vector<int> l;

int dfs(int i, int x, int y, int z) {
  if (i == n) {
    if (x == 0 || y == 0 || z == 0) {
      return inf<int>();
    }
    return abs(a - x) + abs(b - y) + abs(c - z) - 30;
  }
  int r0 = dfs(i + 1, x, y, z);
  int r1 = dfs(i + 1, x + l[i], y, z) + 10;
  int r2 = dfs(i + 1, x, y + l[i], z) + 10;
  int r3 = dfs(i + 1, x, y, z + l[i]) + 10;
  return min({r0, r1, r2, r3});
}

int main() {
  n = in;
  a = in;
  b = in;
  c = in;
  l = Vector<int>(n, in);
  cout << dfs(0, 0, 0, 0) << endl;
}
