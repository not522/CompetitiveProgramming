#include "math/mint.hpp"

int main() {
  Mint::setMod(998244353);
  Mint a(in), b(in), c(in);
  cout << a * (a + 1) / 2 * b * (b + 1) / 2 * c * (c + 1) / 2 << endl;
}
