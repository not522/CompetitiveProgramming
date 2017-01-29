#include "math/mint.hpp"

int main() {
  Mint::setMod(10);
  Mint a, b;
  cin >> a >> b;
  cout << min((int)(a - b), (int)(b - a)) << endl;
}
