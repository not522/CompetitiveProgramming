#include "math.hpp"

int main() {
  int a(in), b(in);
  for (int i = 1;; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (a == round(100 * j, i) && b == round(100 * (i - j), i)) {
        cout << i << endl;
        return 0;
      }
    }
  }
}
