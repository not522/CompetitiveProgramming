#include "math/bitset_matrix.hpp"

int main() {
  int n(in);
  BitsetMatrix m(n);
  for (int i = 0; i < n; ++i) {
    int64_t a(in);
    for (int j = 0; a; ++j, a /= 2) {
      m[i][j] = a % 2;
    }
  }
  cout << (1ll << m.rank()) << endl;
}
