#include "template.hpp"

int main() {
  int l, n;
  cin >> l >> n;
  cout << (1 << (l - 3)) * n << endl;
}
