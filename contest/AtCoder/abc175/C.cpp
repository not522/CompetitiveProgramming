#include "template.hpp"

int main() {
  int64_t x(in), k(in), d(in);
  x = abs(x);
  if (x / d > k) {
    cout << x - k * d << endl;
    return 0;
  }
  k -= x / d;
  x -= x / d * d;
  if (k % 2) {
    x = d - x;
  }
  cout << x << endl;
}
