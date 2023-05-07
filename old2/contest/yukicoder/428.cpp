#include "big_decimal.hpp"

int main() {
  String s = "0.";
  for (int i = 1; i <= 99; ++i) {
    s += String(i);
  }
  s += "1";
  BigDecimal<2, 30> p(s);
  int n(in);
  cout << std::setprecision(200) << p * n << endl;
}
