#include "template.hpp"

int main() {
  int k(in), s(in), res = 0;
  for (int x = 0; x <= k; ++x) {
    for (int y = 0; y <= k; ++y) {
      if (0 <= s - x - y && s - x - y <= k) {
        ++res;
      }
    }
  }
  cout << res << endl;
}
