#include "template.hpp"

int main() {
  string s, r;
  cin >> s;
  r = s;
  reverse(r.begin(), r.end());
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] != r[i] && s[i] != '*' && r[i] != '*') {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
