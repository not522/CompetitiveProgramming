#include "set.hpp"

int main() {
  int x(in), n(in);
  Set<int> p(n, in);
  for (int i = 0;; ++i) {
    if (!p.contains(x - i)) {
      cout << x - i << endl;
      return 0;
    }
    if (!p.contains(x + i)) {
      cout << x + i << endl;
      return 0;
    }
  }
}
