#include "template.hpp"

int main() {
  string s;
  int t, u;
  cin >> s >> t >> u;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i == t || i == u) continue;
    cout << s[i];
  }
  cout << endl;
}
