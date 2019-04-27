#include "template.hpp"

int main() {
  int x, y, x2, y2;
  cin >> x >> y >> x2 >> y2;
  if (x == y && x2 == y2 && x > x2) cout << x + 1 << endl;
  else cout << max(x, y) << endl;
}
