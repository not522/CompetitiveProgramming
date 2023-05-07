#include "math/mint.hpp"

int main() {
  Mint::setMod(10);
  Mint a(in), b(in);
  cout << min(static_cast<int>(a - b), static_cast<int>(b - a)) << endl;
}
