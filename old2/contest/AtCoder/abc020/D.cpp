#include "math/mint.hpp"
#include "math/prime.hpp"
#include "unordered_map.hpp"

int main() {
  int64_t n(in), k(in);
  Prime prime;
  Mint res = 0;
  UnorderedMap<int64_t, Mint> m;
  for (auto d : prime.divisor(k).reverse()) {
    auto s = n / d * (n / d + 1) / 2 * Mint(d);
    for (auto i : m) {
      if (i.first % d == 0) {
        s -= i.second;
      }
    }
    m[d] = s;
    res += s * k / d;
  }
  cout << res << endl;
}
