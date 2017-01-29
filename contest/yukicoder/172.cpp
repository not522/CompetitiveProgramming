#include "math/basic.hpp"

int main() {
  int x, y, r;
  cin >> x >> y >> r;
  cout << (int)floor(max(abs(x - y), abs(x + y)) + r * M_SQRT2) + 1 << endl;
}
