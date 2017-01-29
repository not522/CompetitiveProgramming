#include "math/bitset_matrix.hpp"

int main() {
  int n;
  cin >> n;
  BitsetMatrix m(n);
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    for (int j = 0; a; ++j, a /= 2) m[i][j] = a % 2;
  }
  cout << (1ll << m.rank()) << endl;
}
