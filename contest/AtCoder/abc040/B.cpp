#include "template.hpp"

int main() {
  int n(in), res = inf<int>();
  for (int i = 1; i <= n; ++i) {
    chmin(res, abs(i - n / i) + n % i);
  }
  cout << res << endl;
}
