#include "math/mint.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  vector<Mint> v{0, 1};
  for (int i = 2; i <= b; ++i) v.emplace_back(v.back() / (i - 1) * i + Mint(i) * i);
  cout << accumulate(v.begin() + a, v.begin() + b + 1, Mint(0)) << endl;
}
