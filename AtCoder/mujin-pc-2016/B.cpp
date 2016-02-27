#include "vector.hpp"

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double mx = a + b + c;
  double mn = min({abs(a - b - c), abs(a + b - c), abs(a - b + c)});
  if (2 * max({a, b, c}) < mx) mn = 0;
  cout << (mx * mx - mn * mn) * M_PIl << endl;
}
