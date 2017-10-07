#include "template.hpp"

int main() {
  while (true) {
    int r0, w0, c, r;
    cin >> r0 >> w0 >> c >> r;
    if (r0 == 0 && w0 ==0 && c == 0 && r == 0) break;
    for (int i = 0; ; ++i) {
      if (r0 + i * r >= c * w0) {
        cout << i << endl;
        break;
      }
    }
  }
}
