#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  Mint::setMod(1000003);
  Mint x(in);
  int n(in);
  Mint res = 0;
  for (int i = 0; i < n; ++i) {
    res += pow(x, int(in));
  }
  cout << res << endl;
}
