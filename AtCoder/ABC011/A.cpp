#include "math/mint.hpp"

int main() {
  Mint::setMod(12);
  Mint n;
  cin >> n;
  cout << (int)n + 1 << endl;
}
