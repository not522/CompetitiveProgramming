#include "math/mint.hpp"

int main() {
  int n;
  cin >> n;
  Mint r = 1;
  for (int i = 1; i <= n; ++i) r *= i;
  cout << r << endl;
}
