#include "template.hpp"

int main() {
  int w(in), a(in), b(in);
  if (a <= b && b <= a + w) {
    cout << 0 << endl;
  } else if (a <= b + w && b + w <= a + w) {
    cout << 0 << endl;
  } else {
    cout << min(abs(b - a - w), abs(a - b - w)) << endl;
  }
}
