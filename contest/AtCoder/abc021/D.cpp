#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  int n(in), k(in);
  Combination<Mint> comb;
  cout << comb.combination(n + k - 1, k) << endl;
}
