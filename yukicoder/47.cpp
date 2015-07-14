#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << (n == 1 ? 0 : 32 - __builtin_clz(n - 1)) << endl;
}
