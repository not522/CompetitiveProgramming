#include "template.hpp"

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  tx -= sx;
  ty -= sy;
  cout << string(tx, 'R') << string(ty, 'U');
  cout << string(tx, 'L') << string(ty, 'D');
  cout << 'D' << string(tx + 1, 'R') << string(ty + 1, 'U') << 'L';
  cout << 'U' << string(tx + 1, 'L') << string(ty + 1, 'D') << 'R';
  cout << endl;
}
