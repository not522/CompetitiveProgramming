#include "math/basic.hpp"
#include "math/mint.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  if (abs(n - m) > 1) {
    cout << 0 << endl;
    return 0;
  }
  auto f = factorial_vector<Mint>(max(n, m));
  cout << (2 - abs(n - m)) * f[n] * f[m] << endl;
}
