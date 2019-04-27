#include "math/count_divisor.hpp"

int main() {
  int n, c = 0;
  cin >> n;
  auto v = count_divisor(n);
  for (int i = 1; i <= n; i += 2) {
    if (v[i] == 8) ++c;
  }
  cout << c << endl;
}
