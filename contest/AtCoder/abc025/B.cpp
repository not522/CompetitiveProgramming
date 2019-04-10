#include "string.hpp"

int main() {
  int n(in), a(in), b(in), x = 0;
  for (int i = 0; i < n; ++i) {
    String s(in);
    int d(in);
    if (d < a) {
      d = a;
    }
    if (d > b) {
      d = b;
    }
    if (s == "East") {
      x += d;
    } else {
      x -= d;
    }
  }
  if (x == 0) {
    cout << 0 << endl;
  } else if (x > 0) {
    cout << "East " << x << endl;
  } else {
    cout << "West " << -x << endl;
  }
}
