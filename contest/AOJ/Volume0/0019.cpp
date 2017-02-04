#include "template.hpp"

int main() {
  int64_t n, res = 1;
  cin >> n;
  for (int i = 1; i <= n; ++i) res *= i;
  cout << res << endl;
}
