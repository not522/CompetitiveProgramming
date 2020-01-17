#include "template.hpp"

bool solve(int x1, int y1, int x2, int y2, int x3, int y3) {
  int dx = (x2 - x1), dy = (y2 - y1);
  if (x1 + dy == x3 && y1 - dx == y3) {
    cout << x2 + dy << " " << y2 - dx << endl;
  } else if (x2 + dy == x3 && y2 - dx == y3) {
    cout << x1 + dy << " " << y1 - dx << endl;
  } else if (x1 - dy == x3 && y1 + dx == y3) {
    cout << x2 - dy << " " << y2 + dx << endl;
  } else if (x2 - dy == x3 && y2 + dx == y3) {
    cout << x1 - dy << " " << y1 + dx << endl;
  } else {
    return false;
  }
  return true;
}

int main() {
  int x1(in), y1(in), x2(in), y2(in), x3(in), y3(in);
  if (!solve(x1, y1, x2, y2, x3, y3) && !solve(x1, y1, x3, y3, x2, y2)) {
    cout << -1 << endl;
  }
}
