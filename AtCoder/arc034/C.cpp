#include "math/mint.hpp"
#include "math/prime.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  map<long long, int> m;
  Prime prime;
  for (int i = b + 1; i <= a; ++i) for (auto j : prime.factor(i)) ++m[j];
  cout << accumulate(m.begin(), m.end(), Mint(1), [](Mint a, pair<long long, int> b){return a * (b.second + 1);}) << endl;
}
