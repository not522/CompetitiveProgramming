#include "template.hpp"

int main() {
  int x, y;
  string w;
  cin >> x >> y >> w;
  --x, --y;
  array<string, 9> c;
  for (auto& s : c) cin >> s;
  int dy = 0;
  int dx = 0;
  if (w.find('R') != string::npos) dx = 1;
  if (w.find('L') != string::npos) dx = -1;
  if (w.find('U') != string::npos) dy = -1;
  if (w.find('D') != string::npos) dy = 1;
  for (int i = 0; i < 4; ++i) {
    cout << c[y][x];
    y += dy;
    x += dx;
    if (y < 0 || 9 <= y) {
      dy *= -1;
      y += 2 * dy;
    }
    if (x < 0 || 9 <= x) {
      dx *= -1;
      x += 2 * dx;
    }
  }
  cout << endl;
}
