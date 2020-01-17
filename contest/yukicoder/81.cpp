#include "big_decimal.hpp"

int main() {
  int n(in);
  Vector<BigDecimal<>> v(n, in);
  cout << std::setprecision(10) << v.accumulate() << endl;
}
