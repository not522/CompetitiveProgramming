#include "math/mint.hpp"
#include "string.hpp"

int main() {
  Mint::setMod(26);
  String s(in);
  for (int i = 0; i < s.size(); ++i) {
    cout << char('A' + Mint(s[i] - 'A' - i - 1));
  }
  cout << endl;
}
