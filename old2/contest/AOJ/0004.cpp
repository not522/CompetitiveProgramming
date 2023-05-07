#include "math/square_matrix.hpp"

int main() {
  SquareMatrix<double> m(2);
  Vector<double> v(2);
  while (m[0][0] = in, m[0][1] = in, v[0] = in, m[1][0] = in, m[1][1] = in,
         v[1] = in, !in.eof) {
    auto res = m.inverse() * v;
    cout << std::setprecision(3) << res[0] << " " << res[1] << endl;
  }
}
