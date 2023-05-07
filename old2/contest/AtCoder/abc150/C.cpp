#include "vector.hpp"

int main() {
  int n(in), pn = -1, qn = -1, k = 0;
  Vector<int> p(n, in), q(n, in), perm = iota(n, 1);
  do {
    if (p == perm) {
      pn = k;
    }
    if (q == perm) {
      qn = k;
    }
    ++k;
  } while (perm.next_permutation());
  cout << abs(qn - pn) << endl;
}
