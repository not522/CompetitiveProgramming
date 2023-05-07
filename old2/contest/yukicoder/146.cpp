#include "math/mint.hpp"

int main() {
  int n(in);
  Mint res = 0;
  for (int i = 0; i < n; ++i) {
    int64_t c(in), d(in);
    res += Mint((c + 1) / 2) * d;
  }
  cout << res << endl;
}
