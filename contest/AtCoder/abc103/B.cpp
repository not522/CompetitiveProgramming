#include "template.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }
    s = s.substr(1) + s[0];
  }
  cout << "No" << endl;
}
