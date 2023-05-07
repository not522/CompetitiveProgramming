#include "math/mint_combination.hpp"
#include "math/pow.hpp"
#include "string.hpp"

int main() {
  int k(in);
  String s(in);
  Mint res = 0, p = 1, q = pow(Mint(25), k);
  Combination<Mint> comb(2000000);
  for (int i = 0; i <= k; ++i) {
    res += p * q * comb.combination(k - i + s.size() - 1, s.size() - 1);
    p *= 26;
    q /= 25;
  }
  cout << res << endl;
}
