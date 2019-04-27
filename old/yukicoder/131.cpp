#include "template.hpp"

int main() {
  int x, y, d;
  cin >> x >> y >> d;
  if (x < y) swap(x, y);
  if (d > x + y) cout << 0 << endl;
  else if (d > x) cout << x + y - d + 1 << endl;
  else if (d < y) cout << d + 1 << endl;
  else cout << y + 1 << endl;
}
