#include "template.hpp"

int main() {
  int l, m, n, res = 0;
  cin >> l >> m >> n;
  res += n % 25;
  m += n / 25;
  res += m % 4;
  l += m / 4;
  res += l % 10;
  cout << res << endl;
}
