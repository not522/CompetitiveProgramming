#include "math/square_matrix.hpp"
#include "math/pow.hpp"

int main() {
  int n;
  cin >> n;
  SquareMatrix<int> mat(2);
  mat[0][0] = mat[0][1] = mat[1][0] = 1;
  Vector<int> vec(2);
  vec[0] = 1;
  cout << (pow(mat, n) * vec)[0] << endl;
}
