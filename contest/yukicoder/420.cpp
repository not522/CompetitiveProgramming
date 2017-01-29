#include "math/combination.hpp"

int main() {
  Combination<int64_t> comb;
  int x;
  cin >> x;
  if (x) cout << comb.combination(31, x) << " " << INT_MAX * comb.combination(30, x - 1) << endl;
  else cout << 1 << " " << 0 << endl;
}
