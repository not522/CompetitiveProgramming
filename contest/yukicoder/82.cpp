#include "template.hpp"

int main() {
  int w, h;
  char c;
  cin >> w >> h >> c;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if ((i + j) % 2) cout << char(c ^ 'B' ^ 'W');
      else cout << c;
    }
    cout << endl;
  }
}
