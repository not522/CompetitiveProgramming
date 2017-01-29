#include "template.hpp"

int main() {
  string s;
  int t;
  cin >> s >> t;
  int c = count(s.begin(), s.end(), '?');
  int y = 0, x = 0;
  for (char c : s) {
    switch(c) {
    case 'L': --x; break;
    case 'R': ++x; break;
    case 'U': ++y; break;
    case 'D': --y; break;
    }
  }
  int d = abs(y) + abs(x);
  if (t == 1) {
    cout << d + c << endl;
  } else {
    cout << max(d - c, (d % 2 == c % 2 ? 0 : 1)) << endl;
  }
}
