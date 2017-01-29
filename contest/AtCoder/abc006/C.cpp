#include "math/square_matrix.hpp"

int main() {
  SquareMatrix<double> mat(2);
  mat[0][0] = 3;
  mat[0][1] = 4;
  mat[1][0] = 1;
  mat[1][1] = 1;
  mat = mat.inverse();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    Vector<double> vec(2);
    vec[0] = m - 2 * i;
    vec[1] = n - i;
    vec = mat * vec;
    int j = round(vec[0]);
    int k = round(vec[1]);
    if (j < 0) continue;
    if (k < 0) continue;
    if (i + j + k != n) continue;
    if (2 * i + 3 * j + 4 * k != m) continue;
    cout << i << " " << j << " " << k << endl;
    return 0;
  }
  cout << "-1 -1 -1" << endl;
}
