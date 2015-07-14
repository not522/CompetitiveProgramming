#include "math/basic.hpp"

int main() {
  int x, y, l;
  cin >> x >> y >> l;
  cout << (y < 0 ? 2 : x != 0 ? 1 : 0) + ceil(abs(x), l) + ceil(abs(y), l) << endl;
}
