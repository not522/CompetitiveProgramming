#include "math/mint.hpp"

int main() {
  int n;
  cin >> n;
  Mint res = 0;
  for (int i = 0; i < n; ++i) {
    int64_t c, d;
    cin >> c >> d;
    res += Mint((c + 1) / 2) * d;
  }
  cout << res << endl;
}
