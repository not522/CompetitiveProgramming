#include "math/mint_combination.hpp"

int main() {
  int s(in);
  Mint res;
  Combination<Mint> comb;
  for (int i = 1; i <= s / 3; ++i) {
    res += comb.repetition(i, s - 3 * i);
  }
  cout << res << endl;
}
