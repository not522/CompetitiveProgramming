#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  Mint::setMod(1000003);
  Mint x;
  int n;
  cin >> x >> n;
  Mint res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res += pow(x, a);
  }
  cout << res << endl;
}
