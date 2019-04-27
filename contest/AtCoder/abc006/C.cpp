#include "math.hpp"
#include "math/square_matrix.hpp"

int main() {
  SquareMatrix<double> mat(2);
  mat[0][0] = 3;
  mat[0][1] = 4;
  mat[1][0] = 1;
  mat[1][1] = 1;
  mat = mat.inverse();
  int n(in), m(in);
  for (int i = 0; i <= n; ++i) {
    Vector<double> vec({double(m - 2 * i), double(n - i)});
    vec = mat * vec;
    int j = round(vec[0]), k = round(vec[1]);
    if (0 <= j && 0 <= k && i + j + k == n && 2 * i + 3 * j + 4 * k == m) {
      cout << i << " " << j << " " << k << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
}
