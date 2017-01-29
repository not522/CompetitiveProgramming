#include "template.hpp"

int main() {
  long long a;
  cin >> a;
  for (long long i = 10; ; ++i) {
    long long t = 1, s = 0;
    for (long long j = i; j; j /= 10) {
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
