#include "template.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; ; ++i) {
    if (a % 2 || b % 2 || c % 2) {
      cout << i << endl;
      return 0;
    }
    if (a == b && b == c) {
      cout << -1 << endl;
      return 0;
    }
    int aa = (b + c) / 2;
    int bb = (a + c) / 2;
    int cc = (a + b) / 2;
    a = aa;
    b = bb;
    c = cc;
  }
}
