#include "vector.hpp"

int main() {
  int64_t n(in), k(in), res = 0;
  for (int64_t i = -n + 1; i <= n - 1; ++i) {
    int64_t j  = k - i;
    if (j < -n + 1 || n - 1 < j) {
      continue;
    }
    res += (n - abs(i)) * (n - abs(j));
  }
  cout << res << endl;
}
