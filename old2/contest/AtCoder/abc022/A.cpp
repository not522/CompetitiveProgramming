#include "template.hpp"

int main() {
  int n(in), s(in), t(in), w = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    w += int(in);
    if (s <= w && w <= t) {
      ++res;
    }
  }
  cout << res << endl;
}
