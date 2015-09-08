#include "template.hpp"

int main() {
  array<int, 3> l, a;
  for (int& i : l) cin >> i;
  for (int& i : a) cin >> i;
  sort(l.begin(), l.end());
  int res = numeric_limits<int>::max();
  int sum = 2 * accumulate(l.begin(), l.end(), 0) * accumulate(a.begin(), a.end(), 0);
  do {
    res = min(res, sum - 2 * inner_product(l.begin(), l.end(), a.begin(), 0));
  } while (next_permutation(l.begin(), l.end()));
  cout << res << endl;
}
