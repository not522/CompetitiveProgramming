#include "vector.hpp"
#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  string s;
  cin >> s;
  auto m = count_kinds(s);
  Mint::setMod(573);
  Combination<Mint> comb;
  int n = s.size();
  Mint res = 1;
  for (auto k : m) {
    res *= comb.combination_safety(n, k.second);
    n -= k.second;
  }
  cout << res - 1 << endl;
}
