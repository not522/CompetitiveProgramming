#include "template.hpp"

int main() {
  int64_t a, b, c, k;
  cin >> a >> b >> c >> k;
  auto m = max({a, b, c});
  cout << ((m << k) + a + b + c - m) << endl;
}
