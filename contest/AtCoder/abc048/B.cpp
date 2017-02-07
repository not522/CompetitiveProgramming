#include "math/basic.hpp"

int main() {
  int64_t a, b, x;
  cin >> a >> b >> x;
  cout << b / x - floor(a - 1, x) << endl;
}
