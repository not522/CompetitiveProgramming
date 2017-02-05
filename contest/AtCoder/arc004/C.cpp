#include "math/fraction.hpp"

int main() {
  Fraction<int64_t> f;
  cin >> f.n;
  cin.ignore();
  cin >> f.d;
  f.normalize();
  bool found = false;
  for (int64_t i = max(int64_t(1), 2 * f.n / f.d); ; ++i) {
    auto r = (Fraction<int64_t>(i + 1, 2) - f) * i;
    if (r > i) break;
    if (r.d == 1) {
      cout << i << " " << r.n << endl;
      found = true;
    }
  }
  if (!found) cout << "Impossible" << endl;
}
