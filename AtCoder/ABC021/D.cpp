#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  Combination<Mint> comb;
  cout << comb.combination(n + k - 1, k) << endl;
}
