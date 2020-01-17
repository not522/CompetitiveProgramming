#include "math/polynomial.hpp"

int main() {
  int d(in);
  Polynomial<int> poly(d + 1, in);
  poly %= Polynomial<int>(Vector<int>({0, -1, 0, 1}));
  cout << poly.size() - 1 << endl;
  poly.output(" ");
}
