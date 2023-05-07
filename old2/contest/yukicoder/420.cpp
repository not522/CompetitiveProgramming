#include "math/combination.hpp"

int main() {
  Combination<int64_t> comb;
  int x(in);
  if (x) {
    cout << comb.combination(31, x) << " "
         << ((1ll << 31) - 1) * comb.combination(30, x - 1) << endl;
  } else {
    cout << 1 << " " << 0 << endl;
  }
}
