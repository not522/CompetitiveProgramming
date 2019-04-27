#include "bit_operation.hpp"

int main() {
  int64_t h, w;
  cin >> h >> w;
  cout << (count_bit(w) != 1 || count_bit(h) == 1 || count_bit(h + 1) == 1 ? (2ll << most_bit(h * w - 1)) - 1: (2ll << most_bit(h * w - 1)) - w) << endl;
}
