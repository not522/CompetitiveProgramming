#include "math/mint_combination.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  Combination<Mint> comb(n + k);
  if (n > k) cout << comb.repetition(n, k) << endl;
  else cout << comb.combination(n, k % n) << endl;
}
