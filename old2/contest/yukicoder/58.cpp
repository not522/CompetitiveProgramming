#include "math/pow.hpp"
#include "math/square_matrix.hpp"

int main() {
  int n(in), k(in), mx = 6 * n;
  SquareMatrix<double> m1(mx + 1), m2(mx + 1);
  for (int i = 0; i < mx; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i + j <= mx) {
        m1[i + j][i] = 1.0 / 6;
      }
    }
    for (int j = 4; j <= 6; ++j) {
      if (i + j <= mx) {
        m2[i + j][i] = 2.0 / 6;
      }
    }
  }
  Vector<double> v(mx + 1);
  v[0] = 1;
  auto taro = pow(m1, n - k) * pow(m2, k) * v;
  auto jiro = pow(m1, n) * v;
  double res = 0;
  for (int i = 0; i <= mx; ++i) {
    for (int j = 0; j < i; ++j) {
      res += taro[i] * jiro[j];
    }
  }
  cout << res << endl;
}
