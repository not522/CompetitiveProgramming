#include "math/mint_combination.hpp"
#include "math/prime.hpp"

int main() {
  int n, m;
  Prime prime;
  Combination<Mint> comb;
  cin >> n >> m;
  auto f = prime.primeFactor(m);
  Mint res = 1;
  for (int i = 0; i < int(f.size()); ++i) {
    int k = 0, mm = m;
    for (; mm % f[i] == 0; ++k) mm /= f[i];
    res *= comb.repetition(n, k);
  }
  cout << res << endl;
}
