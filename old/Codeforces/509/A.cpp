#include "math/combination.hpp"

int main() {
  int n;
  cin >> n;
  Combination<int> comb;
  cout << comb.combination(2 * n - 2, n - 1) << endl;
}
