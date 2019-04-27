#include "math/mint.hpp"

int main() {
  int n(in);
  Mint r = 1;
  for (int i = 1; i <= n; ++i) {
    r *= i;
  }
  cout << r << endl;
}
