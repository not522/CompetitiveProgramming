#include "math/circulant_matrix.hpp"
#include "math/pow.hpp"

int main() {
  auto v = iota(6, 1);
  CirculantMatrix<int> m(6);
  m[5] = 1;
  int n(in);
  v = pow(m, n / 5) * v;
  for (int i = 0; i < n % 5; ++i) {
    swap(v[i], v[i + 1]);
  }
  v.output("");
}
