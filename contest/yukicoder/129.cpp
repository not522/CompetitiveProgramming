#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  int64_t n(in), m(in);
  n /= 1000;
  n %= m;
  Mint::setMod(1000000000);
  Combination<Mint> comb;
  cout << comb.combination_safety(m, n) << endl;
}
