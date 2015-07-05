#include "math/pow.hpp"
#include "math/permutation_matrix.hpp"

int main() {
  int n, m , d;
  cin >> n >> m >> d;
  PermutationMatrix mat(n);
  mat = mat.identity();
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    swap(mat[a - 1], mat[a]);
  }
  mat = pow(mat, d);
  mat = mat.inverse();
  for (int i = 0; i < n; ++i) cout << mat[i] + 1 << endl;
}
