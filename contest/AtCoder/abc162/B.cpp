#include "template.hpp"

int main() {
  int64_t n(in), res = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 3 && i % 5) {
      res += i;
    }
  }
  cout << res << endl;
}
