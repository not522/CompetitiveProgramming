#include "template.hpp"

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a <= b && b <= a + w) cout << 0 << endl;
  else if (a <= b + w && b + w <= a + w) cout << 0 << endl;
  else cout << min(abs(b - a - w), abs(a - b - w)) << endl;
}
