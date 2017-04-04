#include "template.hpp"

int main() {
  int64_t n, m;
  cin >> n >> m;
  cout << min(m / 2, (2 * n + m) / 4) << endl;
}
