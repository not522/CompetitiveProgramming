#include "math/mint.hpp"
#include "math/combination.hpp"

int main() {
  int r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;
  Combination<Mint> combination;
  Mint k = 0;
  for (int i1 = 0; i1 <= 1; ++i1) {
    for (int i2 = 0; i2 <= 1; ++i2) {
      if (x <= i1 + i2) continue;
      for (int i3 = 0; i3 <= 1; ++i3) {
        for (int i4 = 0; i4 <= 1; ++i4) {
          if (y <= i3 + i4) continue;
          int p = (i1 + i2 + i3 + i4) % 2 ? -1 : 1;
          k += p * combination.combination((x - i1 - i2) * (y - i3 - i4), d) * combination.combination((x - i1 - i2) * (y - i3 - i4) - d, l);
        }
      }
    }
  }
  cout << k * Mint(r - x + 1) * Mint(c - y + 1) << endl;
}