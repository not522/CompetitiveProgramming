#include "math/mint.hpp"
#include "math/prime.hpp"
#include "math/inclusion_exclusion_principle.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  Prime prime;
  Mint res = 0;
  for (int64_t i : prime.divisor(k)) {
    auto f = [&](const vector<int64_t>& v){
      Mint p = accumulate(v.begin(), v.end(), Mint(1), std::multiplies<Mint>());
      return n / i / p * (n / i / p + 1) / 2 * p;
    };
    res += inclusionExclusionPrinciple(prime.primeFactor(k / i), f, Mint(0)) * k;
  }
  cout << res << endl;
}
