#include "template.hpp"

int main() {
  string s;
  cin >> s;
  set<char> c(s.begin(), s.end());
  if (c.size() == 4u) {
    cout << "Yes" << endl;
  } else if (c.size() == 2u) {
    if ((c.count('N') && c.count('S')) || (c.count('W') && c.count('E'))) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else {
    cout << "No" << endl;
  }
}
