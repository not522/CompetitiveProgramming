#include "template.hpp"

int main() {
  long long n;
  cin >> n;
  for (long long i = sqrt(n); i * (i + 1) / 2 <= n; ++i) {
    if (i * (i + 1) / 2 == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
