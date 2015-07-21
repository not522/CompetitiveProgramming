#include "big_decimal.hpp"

int main() {
  int n;
  cin >> n;
  vector<BigDecimal<>> v(n);
  for (auto& i : v) cin >> i;
  cout << setprecision(10) << accumulate(v.begin(), v.end(), BigDecimal<>()) << endl;
}
