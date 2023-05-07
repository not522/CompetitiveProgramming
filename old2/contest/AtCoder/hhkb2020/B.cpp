#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in), res = 0;
  Vector<String> s(h, in);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] != '.') {
        continue;
      }
      if (j + 1 < w && s[i][j + 1] == '.') {
        ++res;
      }
      if (i + 1 < h && s[i + 1][j] == '.') {
        ++res;
      }
    }
  }
  cout << res << endl;
}
