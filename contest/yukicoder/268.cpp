#include "vector.hpp"

int main() {
  Vector<int> l(3, in), a(3, in);
  l.sort();
  int res = inf<int>();
  int sum = 2 * l.accumulate() * a.accumulate();
  do {
    chmin(res, sum - 2 * l.inner_product(a));
  } while (l.next_permutation());
  cout << res << endl;
}
