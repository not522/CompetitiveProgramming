#include "math/basic.hpp"

int main() {
  int n, d;
  cin >> n >> d;
  cout << n / gcd(n, d) - 1 << endl;
}
