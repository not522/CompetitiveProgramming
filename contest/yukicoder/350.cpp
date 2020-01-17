#include "big_decimal.hpp"

int main() {
  BigDecimal<> v(in), t(in);
  cout << int((v * t).toDouble()) << endl;
}
