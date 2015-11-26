#include "template.hpp"

int main() {
  int l, m, n;
  cin >> l >> m >> n;
  m += n / 25;
  l += m / 4;
  cout << n % 25 + m % 4 + l % 10 << endl;
}
