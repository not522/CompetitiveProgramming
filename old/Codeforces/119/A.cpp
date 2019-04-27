#include "math/basic.hpp"

int main() {
  int a[2], n;
  cin >> a[0] >> a[1] >> n;
  while (true) {
    for (int i = 0; i < 2; ++i) {
      int g = gcd(a[i], n);
      n -= g;
      if (n < 0) {
        cout << 1 - i << endl;
        return 0;
      }
    }
  }
}
