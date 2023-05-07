#include "template.hpp"

int main() {
  auto tax = [](int x, int p) { return x * (100 + p) / 100; };
  for (int x, y, s; x = in, y = in, s = in, x != 0 || y != 0 || s != 0;) {
    int res = -1;
    for (int i = 1; i < s; ++i) {
      for (int j = i; j < s; ++j) {
        if (tax(i, x) + tax(j, x) == s) {
          chmax(res, tax(i, y) + tax(j, y));
        }
      }
    }
    cout << res << endl;
  }
}
