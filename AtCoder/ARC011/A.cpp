#include "template.hpp"

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  int res = k;
  while (k >= m) {
    res += k / m * n;
    k = k % m + k / m * n;
  }
  cout << res << endl;
}
