#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int k = 0;
  for (char c : s) {
    if (k == 0 && tolower(c) == 'i') ++k;
    if (k == 1 && tolower(c) == 'c') ++k;
    if (k == 2 && tolower(c) == 't') ++k;
  }
  cout << (k == 3 ? "YES" : "NO") << endl;
}
