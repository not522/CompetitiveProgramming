#include "string.hpp"

int main() {
  int res1 = 0, res2 = 0;
  for (String line; line = in, !in.eof;) {
    auto v = line.split(',');
    int a = v[0];
    int b = v[1];
    int c = v[2];
    if (a * a + b * b == c * c) {
      ++res1;
    }
    if (a == b) {
      ++res2;
    }
  }
  cout << res1 << endl << res2 << endl;
}
