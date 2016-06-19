#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  int64_t n, m, p;
  cin >> n >> m >> p;
  Mint::setMod(m);
  cout << pow(Mint(n), p) << endl;
}
