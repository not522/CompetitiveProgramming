#include "vector.hpp"

int main() {
  vector<int> l(3), a(3);
  cin >> l >> a;
  sort(l);
  int res = numeric_limits<int>::max();
  int sum = 2 * accumulate(l) * accumulate(a);
  do {
    res = min(res, sum - 2 * inner_product(l, a));
  } while (next_permutation(l));
  cout << res << endl;
}
