#include "template.hpp"

int main() {
  int64_t x(in), t = 100;
  for (int i = 1;; ++i) {
    t += t / 100;
    if (t >= x) {
      cout << i << endl;
      break;
    }
  }
}
