#include "template.hpp"

int main() {
  int t, a, b, c, d;
  cin >> t >> a >> b >> c >> d;
  if (a + c <= t) {
    cout << b + d << endl;
  } else if (c <= t) {
    cout << d << endl;
  } else if (a <= t) {
    cout << b << endl;
  } else {
    cout << 0 << endl;
  }
}
