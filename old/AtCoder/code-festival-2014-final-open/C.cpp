#include "template.hpp"

int main() {
  int64_t a;
  cin >> a;
  for (int64_t i = 10; ; ++i) {
    int64_t t = 1, s = 0;
    for (int64_t j = i; j; j /= 10) {
      s += j % 10 * t;
      t *= i;
    }
    if (a == s) {
      cout << i << endl;
      return 0;
    }
    if (a < s) break;
  }
  cout << -1 << endl;
}
