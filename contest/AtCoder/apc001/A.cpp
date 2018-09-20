#include "template.hpp"

int main() {
  int64_t x, y;
  cin >> x >> y;
  cout << (x % y ? x : -1) << endl;
}
