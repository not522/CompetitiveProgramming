#include "string.hpp"

int main() {
  String s(in);
  int t(in), c = s.count('?'), y = 0, x = 0;
  for (char c : s) {
    if (c == 'L') {
      --x;
    } else if (c == 'R') {
      ++x;
    } else if (c == 'U') {
      ++y;
    } else if (c == 'D') {
      --y;
    }
  }
  int d = abs(y) + abs(x);
  if (t == 1) {
    cout << d + c << endl;
  } else {
    cout << max(d - c, (d % 2 == c % 2 ? 0 : 1)) << endl;
  }
}
