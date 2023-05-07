#include "vector.hpp"

int main() {
  for (int m, nmin, nmax; m = in, nmin = in, nmax = in, m != 0;) {
    Vector<int> p(m, in);
    p = p.adjacent_difference().subvector(nmin, nmax + 1).reverse();
    cout << nmax - p.argmin() << endl;
  }
}
