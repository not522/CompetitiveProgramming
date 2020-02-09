#include "container/bitset.hpp"

int main() {
  int n(in), s(in);
  Bitset bit(n);
  for (int i = 0; i < n; ++i) {
    bit[i] = in;
  }
  bit <<= s;
  for (int i = 0; i < n + s; ++i) {
    if (bit[i]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
