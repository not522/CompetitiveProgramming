#include "math/basic.hpp"

int main() {
  for (int a, b; cin >> a >> b;) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
}
