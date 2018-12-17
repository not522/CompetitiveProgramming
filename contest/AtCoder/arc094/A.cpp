#include "template.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = max({a, b, c});
  if (mx % 2 != (a + b + c) % 2) ++mx;
  cout << (3 * mx - a - b - c) / 2 << endl;
}
