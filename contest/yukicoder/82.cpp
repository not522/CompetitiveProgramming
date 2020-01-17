#include "template.hpp"

int main() {
  int w(in), h(in);
  char c(in);
  cerr << int(c) << endl;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if ((i + j) % 2) {
        cout << char(c ^ 'B' ^ 'W');
      } else {
        cout << c;
      }
    }
    cout << endl;
  }
}
