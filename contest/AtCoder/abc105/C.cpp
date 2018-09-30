#include "template.hpp"

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  string r;
  for (int i = 1; n; i *= -1, n /= 2) {
    r = to_string(abs(n) % 2) + r;
    n -= abs(n) % 2 * i;
  }
  cout << r << endl;
}
