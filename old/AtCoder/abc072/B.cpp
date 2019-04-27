#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()); i += 2) cout << s[i];
  cout << endl;
}
