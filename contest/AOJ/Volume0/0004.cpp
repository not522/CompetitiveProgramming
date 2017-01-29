#include "math/square_matrix.hpp"

int main() {
  SquareMatrix<double> m(2);
  Vector<double> v(2);
  while (cin >> m[0][0] >> m[0][1] >> v[0] >> m[1][0] >> m[1][1] >> v[1]) {
    auto res = m.inverse() * v;
    cout << setprecision(3) << res[0] << " " << res[1] << endl;
  }
}
