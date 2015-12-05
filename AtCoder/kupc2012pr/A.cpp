#include "template.hpp"

int main() {
  int m, n;
  cin >> m >> n;
  if (m == 0) cout << n + 1 << endl;
  if (m == 1) cout << n + 2 << endl;
  if (m == 2) cout << 2 * n + 3 << endl;
  if (m == 3) cout << (1ll << (n + 3)) - 3 << endl;
}
