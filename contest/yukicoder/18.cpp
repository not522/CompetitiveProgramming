#include "math/mint.hpp"

int main() {
  Mint::setMod(26);
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()); ++i) cout << char('A' + Mint(s[i] - 'A' - i - 1));
  cout << endl;
}
