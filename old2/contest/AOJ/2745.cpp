#include "template.hpp"

int main() {
  for (int r0, w0, c, r; r0 = in, w0 = in, c = in, r = in, r0 != 0;) {
    for (int i = 0;; ++i) {
      if (r0 + i * r >= c * w0) {
        cout << i << endl;
        break;
      }
    }
  }
}
