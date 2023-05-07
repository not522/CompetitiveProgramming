#include "template.hpp"

int main() {
  int k(in), s = 7;
  for (int i = 1; i <= k; ++i) {
    if (s % k == 0) {
      cout << i << endl;
      return 0;
    }
    s = (10 * s + 7) % k;
  }
  cout << -1 << endl;
}
