#include "math/basic.hpp"

int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
}
