#include "template.hpp"

int main() {
  string s;
  cin >> s;
  s += ".";
  int p = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[p] != s[i]) {
      cout << s[p] << i - p;
      p = i;
    }
  }
  cout << endl;
}
