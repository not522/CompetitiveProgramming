#include "math/square_matrix.hpp"

int main() {
  int n;
  cin >> n;
  SquareMatrix<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> b[i][j];
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> c[i][j];
  cout << (a * b == c ? "YES" : "NO") << endl;
}
