#include "math/basic.hpp"

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  int l = lcm(a, b);
  cout << ceil(n, l) * l << endl;
}
