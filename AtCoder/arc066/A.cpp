#include "vector.hpp"
#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  for (int i = 0; i < n; ++i) {
    if (a[i] == (i + n % 2) / 2 * 2 + (1 - n % 2)) continue;
    cout << 0 << endl;
    return 0;
  }
  cout << pow(Mint(2), n / 2) << endl;
}
