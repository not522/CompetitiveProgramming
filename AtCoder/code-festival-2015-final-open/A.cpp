#include "template.hpp"

int main() {
  string s, t, u;
  cin >> s >> t >> u;
  cout << (s.size() == 5u && t.size() == 7u && u.size() == 5u ? "valid" : "invalid") << endl;
}
