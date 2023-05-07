#include "template.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), m(in), x(in), y(in);
  (void)n;
  --x;
  --y;
  x %= 2 * m;
  y %= 2 * m;
  if (x >= m) {
    x = 2 * m - x - 1;
  }
  if (y >= m) {
    y = 2 * m - y - 1;
  }
  cout << (x == y) << endl;
}
