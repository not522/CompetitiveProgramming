#include "template.hpp"

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x; --y;
  x %= 2 * m;
  y %= 2 * m;
  if (x >= m) x = 2 * m - x - 1;
  if (y >= m) y = 2 * m - y - 1;
  cout << (x == y ? "YES" : "NO") << endl;
}
