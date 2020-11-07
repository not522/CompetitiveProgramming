#include "math.hpp"

int main() {
  int k(in), res = 0;
  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) {
        res += gcd(a, b, c);
      }
    }
  }
  cout << res << endl;
}
