#include "math/pow.hpp"
#include "math/square_matrix.hpp"

int main() {
  SquareMatrix<int64_t> m(2);
  m[0][0] = m[0][1] = m[1][0] = 1;
  Vector<int64_t> v(2);
  v[0] = 1;
  int n(in);
  cout << (pow(m, n) * v)[0] << endl;
}
