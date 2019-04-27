#include "big_decimal.hpp"

int main() {
  BigDecimal<> v, t;
  cin >> v >> t;
  cout << int((v * t).toDouble()) << endl;
}
