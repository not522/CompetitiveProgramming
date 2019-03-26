#include "math/bitwise_square_matrix.hpp"
#include "math/pow.hpp"

int main() {
  int k(in), m(in);
  Vector<unsigned int> a(k, in), c(k, in);
  SquareMatrix<Bitwise<unsigned int>> mat(k);
  for (int i = 0; i < k; ++i) {
    mat[0][i] = c[i];
  }
  for (int i = 0; i < k - 1; ++i) {
    mat[i + 1][i] = numeric_limits<unsigned int>::max();
  }
  Vector<Bitwise<unsigned int>> vec(k);
  for (int i = 0; i < k; ++i) {
    vec[i] = a[k - i - 1];
  }
  cout << (pow(mat, m - 1) * vec)[k - 1].val << endl;
}
