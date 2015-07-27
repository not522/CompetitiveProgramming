#include "template.hpp"

int main() {
  int m, n, res = -1;
  cin >> m >> n;
  while (m != 0 && n != 0) {
    if (m >= n) {
      res += m / n;
      m %= n;
    } else {
      ++res;
      swap(m, n);
    }
  }
  cout << res << endl;
}
