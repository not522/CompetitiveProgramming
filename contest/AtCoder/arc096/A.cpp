#include "minmax.hpp"

int main() {
  int a, b, c, x, y, res = numeric_limits<int>::max();
  cin >> a >> b >> c >> x >> y;
  for (int i = 0; i <= 200000; ++i) chmin(res, a * max(x - i / 2, 0) + b * max(y - i / 2, 0) + c * i);
  cout << res << endl;
}
