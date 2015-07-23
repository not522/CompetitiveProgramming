#include "template.hpp"

int main() {
  int a, b, s;
  cin >> a >> b >> s;
  if (abs(s - a) > abs(s - b) && s != 1) {
    if (a == 0) cout << abs(s - b) + abs(s - a) + a + 1 << endl;
    else cout << abs(s - b) + min(abs(s - a), s - 1) + a << endl;
  } else {
    cout << abs(s - a) + s << endl;
  }
}
