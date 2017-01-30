#include "dp/unbounded_knapsack.hpp"
#include "math/mint.hpp"

int main() {
  Mint::setMod(1000000009);
  vector<int> w(9);
  iota(w.begin(), w.end(), 1);
  auto v = unboundedKnapsackCount<int, Mint>(100000, w);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long m;
    cin >> m;
    Mint res = 0;
    for (int j = 0; j <= m / 111111; ++j) res += v[j];
    cout << res << endl;
  }
}