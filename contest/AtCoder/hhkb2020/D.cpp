#include "math.hpp"
#include "math/mint.hpp"

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    int n(in), a(in), b(in);
    if (n < a + b) {
      cout << 0 << endl;
    } else {
      Mint res =
          2 * Mint(n - a - b + 1) * (n - a - b + 2) * (n - a + 1) * (n - b + 1);
      res -= square(Mint(n - a - b + 1) * (n - a - b + 2));
      cout << res << endl;
    }
  }
}
