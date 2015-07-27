#include "math/basic.hpp"
#include "math/mint.hpp"

int main() {
  int l;
  cin >> l;
  Mint::setMod(1000003);
  Mint res = 0;
  for (int i = 1; i * i < l; ++i) {
    for (int j = i % 2 + 1; j < i && 2 * i * (i + j) <= l / 4; j += 2) {
      if (gcd(i, j) == 1) ++res;
    }
  }
  cout << res << endl;
}
