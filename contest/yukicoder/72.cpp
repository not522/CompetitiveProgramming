#include "math/mint.hpp"

int main() {
  Mint::setMod(1000007);
  long long n;
  cin >> n;
  Mint a = n / 2 + 1, b = (n + 1) / 2 + 1;
  cout << a * b - 1 << endl;
}
