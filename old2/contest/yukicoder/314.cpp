#include "math/mint_square_matrix.hpp"
#include "math/pow.hpp"

int main() {
  int n(in);
  SquareMatrix<Mint> mat(3);
  mat[0][1] = 1;
  mat[0][2] = 1;
  mat[1][0] = 1;
  mat[2][1] = 1;
  mat = pow(mat, n - 1);
  cout << mat[0].accumulate() << endl;
}
