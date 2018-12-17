#include "bit_operation.hpp"

int main() {
  int64_t x, y;
  cin >> x >> y;
  cout << most_bit(y / x) + 1 << endl;
}
