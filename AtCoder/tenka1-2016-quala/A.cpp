#include "template.hpp"

int main() {
  int res = 0;
  for (int i = 1; i <= 100; ++i) {
    if (i % 3 && i % 5) res += i;
  }
  cout << res << endl;
}
