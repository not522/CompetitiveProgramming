#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (s[0] != 'A' || count(s.begin() + 2, s.end() - 1, 'C') != 1) {
    cout << "WA" << endl;
    return 0;
  }
  int k = 0;
  for (char c : s) {
    if (isupper(c)) ++k;
  }
  cout << (k == 2 ? "AC" : "WA") << endl;
}
