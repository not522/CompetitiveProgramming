#include "math/polynomial.hpp"

int main() {
  Polynomial<int> poly;
  poly = poly.identity();
  for (int i = 0; i < 4; ++i) poly *= Polynomial<int>(10, 1);

  int n;
  while (cin >> n) cout << poly[n] << endl;
}
