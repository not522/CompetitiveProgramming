#include "math/mint.hpp"
#include "math/pow.hpp"
#include "math/square_matrix.hpp"

int main() {
  int n;
  cin >> n;
  SquareMatrix<Mint> mat(3);
  mat[0][1] = 1;
  mat[0][2] = 1;
  mat[1][0] = 1;
  mat[2][1] = 1;
  mat = pow(mat, n - 1);
  cout << accumulate(mat[0].begin(), mat[0].end(), Mint()) << endl;
}
