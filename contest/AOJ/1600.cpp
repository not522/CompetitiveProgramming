#include "vector.hpp"

int main() {
  for (int m, nmin, nmax; cin >> m >> nmin >> nmax, m != 0;) {
    Vector<int> p(m, cin);
    p = p.adjacent_difference().subvector(nmin, nmax + 1).reverse();
    cout << nmax - p.argmin() << endl;
  }
}
