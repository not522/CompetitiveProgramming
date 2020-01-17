#include "math/combination.hpp"
#include "math/mint.hpp"
#include "set.hpp"
#include "string.hpp"
#include "vector.hpp"

Map<char, int> count(const String &t) {
  Map<char, int> res;
  for (const auto &i : t) {
    ++res[i];
  }
  return res;
}

int main() {
  String s(in);
  auto m = count(s);
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
