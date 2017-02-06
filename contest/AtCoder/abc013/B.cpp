#include "math/mint.hpp"

int main() {
  Mint::setMod(10);
  Mint a, b;
  cin >> a >> b;
  cout << min(static_cast<int>(a - b), static_cast<int>(b - a)) << endl;
}
