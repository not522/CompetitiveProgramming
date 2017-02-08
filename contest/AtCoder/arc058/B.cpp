#include "math/mint_combination.hpp"

int main() {
  Combination<Mint> comb(2e5);
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  Mint res;
  for (int i = 0; i < h - a; ++i) {
    res += comb.combination(i + b - 1, i) * comb.combination(h + w - i - b - 2, h - i - 1);
  }
  cout << res << endl;
}
