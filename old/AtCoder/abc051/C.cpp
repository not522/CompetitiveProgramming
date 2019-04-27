#include "string.hpp"

int main() {
  int sx(in), sy(in), tx(in), ty(in);
  tx -= sx;
  ty -= sy;
  cout << String(tx, 'R') << String(ty, 'U');
  cout << String(tx, 'L') << String(ty, 'D');
  cout << 'D' << String(tx + 1, 'R') << String(ty + 1, 'U') << 'L';
  cout << 'U' << String(tx + 1, 'L') << String(ty + 1, 'D') << 'R';
  cout << endl;
}
