#include "template.hpp"

int main() {
  int64_t n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) cout << 1 << endl;
  else if (n == 1 || m == 1) cout << n * m - 2 << endl;
  else cout << (n - 2) * (m - 2) << endl;
}
