#include "template.hpp"

int main() {
  string s, t = "hello";
  cin >> s;
  size_t i = 0;
  for (char c : s) {
    if (c == t[i]) ++i;
  }
  cout << (i == t.size() ? "YES" : "NO") << endl;
}
