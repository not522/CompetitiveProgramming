#include "math/permutation_matrix.hpp"
#include "math/pow.hpp"

int main() {
  int n(in), m(in), d(in);
  auto mat = PermutationMatrix::identity(n);
  for (int i = 0; i < m; ++i) {
    int a(in);
    swap(mat[a - 1], mat[a]);
  }
  (pow(mat, d).inverse() + 1).output();
}
