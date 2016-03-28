#include "template.hpp"

int main() {
  int n, k = 0;
  cin >> n;
  for (int i = 1; ; ++i) {
    k += i;
    n -= k;
    if (n < 0) {
      cout << i - 1 << endl;
      return 0;
    }
  }
}
