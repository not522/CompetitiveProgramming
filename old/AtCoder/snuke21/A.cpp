#include "template.hpp"

int main() {
  int64_t n;
  cin >> n;
  for (int64_t i = sqrt(n); i * (i + 1) / 2 <= n; ++i) {
    if (i * (i + 1) / 2 == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
