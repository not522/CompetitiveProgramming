#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << ((s.size() % 2 == 0u) == (s[0] == s.back()) ? "First" : "Second") << endl;
}
