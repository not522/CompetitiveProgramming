#include "template.hpp"

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int a = 0, b = 0, c = 0;
    bool p = true;
    for (char t : s) {
      if (t == 'W') {
        a = min(a + 1, b);
        if (b == 0) p = false;
      }
      if (t == 'G') {
        ++b;
        if (b > c) p = false;
      }
      if (t == 'R') ++c;
    }
    if (a < b || b != c || c == 0) p = false;
    cout << (p ? "possible" : "impossible") << endl;
  }
}
