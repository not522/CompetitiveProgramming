#include "template.hpp"

int main() {
  int n(in), k(in), res = 0;
  for (; n > 0; n /= k) {
    ++res;
  }
  cout << res << endl;
}
