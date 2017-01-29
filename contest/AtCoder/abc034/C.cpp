#include "math/mint_combination.hpp"

int main() {
  int w, h;
  cin >> w >> h;
  Combination<Mint> comb;
  cout << comb.combination(w + h - 2, w - 1) << endl;
}
