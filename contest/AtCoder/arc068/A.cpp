#include "template.hpp"

int main() {
  int64_t x;
  cin >> x;
  cout << x / 11 * 2 + (x % 11 > 0 ? x % 11 > 6 ? 2 : 1 : 0) << endl;
}
