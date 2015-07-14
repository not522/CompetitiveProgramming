#include "template.hpp"

int main() {
  int x, y, k;
  cin >> x >> y >> k;
  cout << x + min(y, k) - max(0, k - y) << endl;
}
