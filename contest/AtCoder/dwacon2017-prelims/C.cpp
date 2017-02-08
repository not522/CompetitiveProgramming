#include "math/basic.hpp"

int main() {
  int n, c[4]{}, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++c[a - 1];
  }
  res += c[1] / 2 + c[2] + c[3];
  c[0] -= c[2];
  c[1] %= 2;
  if (c[1] % 2) {
    ++res;
    c[0] -= 2;
  }
  cout << res + max(ceil(c[0], 4), 0) << endl;
}
