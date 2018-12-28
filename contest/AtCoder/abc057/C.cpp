#include "template.hpp"

int main() {
  int64_t n, r = numeric_limits<int64_t>::max();
  cin >> n;
  for (int64_t a = 1; a * a <= n; ++a) {
    if (n % a) continue;
    chmin(r, int64_t(log10(n / a)) + 1);
  }
  cout << r << endl;
}
