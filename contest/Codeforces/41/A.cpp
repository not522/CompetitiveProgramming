#include "template.hpp"

int main() {
  string s, t;
  cin >> s >> t;
  reverse(t.begin(), t.end());
  cout << (s == t ? "YES" : "NO") << endl;
}
