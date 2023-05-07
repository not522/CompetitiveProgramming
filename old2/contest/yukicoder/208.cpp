#include "template.hpp"

int main() {
  int x(in), y(in), x2(in), y2(in);
  if (x == y && x2 == y2 && x > x2) {
    cout << x + 1 << endl;
  } else {
    cout << max(x, y) << endl;
  }
}
