#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  int n;
  cin >> n;
  Mint res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; i * j <= n; ++j) {
      res += pow(Mint(i), 10) * pow(Mint(j), 10);
      res -= pow(Mint(i - 1), 10) * pow(Mint(j), 10);
      res -= pow(Mint(i), 10) * pow(Mint(j - 1), 10);
      res += pow(Mint(i - 1), 10) * pow(Mint(j - 1), 10);
    }
  }
  cout << res << endl;
}
