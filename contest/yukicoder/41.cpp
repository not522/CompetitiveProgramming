#include "dp/unbounded_knapsack.hpp"
#include "math/mint.hpp"

int main() {
  Mint::setMod(1000000009);
  Vector<int> w(9);
  iota(w.begin(), w.end(), 1);
  auto v = unboundedKnapsackCount<int, Mint>(100000, w);
  int t(in);
  for (int i = 0; i < t; ++i) {
    int64_t m(in);
    Mint res = 0;
    for (int j = 0; j <= m / 111111; ++j) {
      res += v[j];
    }
    cout << res << endl;
  }
}
