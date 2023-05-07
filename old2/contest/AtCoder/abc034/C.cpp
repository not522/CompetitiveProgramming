#include "math/mint_combination.hpp"

int main() {
  int w(in), h(in);
  Combination<Mint> comb;
  cout << comb.combination(w + h - 2, w - 1) << endl;
}
