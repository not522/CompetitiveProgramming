#include "template.hpp"

int main() {
  int n(in), k(in), t = 0;
  if ((n - 1) % (k + 1) == 0) {
    cout << 0 << endl;
    t = in;
  }
  while (t < n) {
    cout << t + (n - 1 - t) % (k + 1) << endl;
    t = in;
  }
}
