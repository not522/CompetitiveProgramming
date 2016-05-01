#include "template.hpp"

int main() {
  int x1, y1, r, x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
  if (x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3) {
    cout << "NO" << endl;
    cout << "YES" << endl;
  } else if (hypot(x1 - x2, y1 - y2) <= r && hypot(x1 - x2, y1 - y3) <= r && hypot(x1 - x3, y1 - y2) <= r && hypot(x1 - x3, y1 - y3) <= r) {
    cout << "YES" << endl;
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << "YES" << endl;
  }
}
