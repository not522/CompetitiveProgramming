#include "math/polynomial.hpp"
#include "string/to_string.hpp"

int main() {
  int d;
  cin >> d;
  Polynomial<int> poly;
  for (int i = 0; i <= d; ++i) cin >> poly[i];
  poly %= Polynomial<int>(vector<int>({0, -1, 0, 1}));
  cout << poly.size() - 1 << endl;
  cout << to_string(poly) << endl;
}
