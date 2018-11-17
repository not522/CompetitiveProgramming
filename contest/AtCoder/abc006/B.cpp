#include "math/mint_square_matrix.hpp"
#include "math/pow.hpp"

int main() {
  Mint::setMod(10007);
  SquareMatrix<Mint> m(3);
  m[0][0] = m[0][1] = m[0][2] = m[1][0] = m[2][1] = 1;
  Vector<Mint> v(3);
  v[0] = 1;
  int n;
  cin >> n;
  cout << (pow(m, n - 3) * v)[0] << endl;
}
