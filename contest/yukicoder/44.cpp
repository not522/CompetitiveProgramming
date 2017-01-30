#include "math/square_matrix.hpp"
#include "math/pow.hpp"

int main() {
  SquareMatrix<long long> m(2);
  m[0][0] = m[0][1] = m[1][0] = 1;
  Vector<long long> v(2);
  v[0] = 1;
  int n;
  cin >> n;
  cout << (pow(m, n) * v)[0] << endl;
}