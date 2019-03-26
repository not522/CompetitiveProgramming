#pragma once
#include "math/mint.hpp"
#include "math/square_matrix.hpp"

template<> SquareMatrix<Mint> SquareMatrix<Mint>::inverse() const {
  int n = this->size();
  SquareMatrix mat = *this;
  SquareMatrix inv = identity();
  for (int i = 0; i < n; ++i) {
    int p = i;
    for (int j = i + 1; j < n; ++j) {
      if (int64_t(mat[j][i]) > int64_t(mat[p][i])) p = j;
    }
    mat[i].swap(mat[p]);
    inv[i].swap(inv[p]);
    for (int j = i + 1; j < n; ++j) mat[i][j] /= mat[i][i];
    for (int j = 0; j < n; ++j) inv[i][j] /= mat[i][i];
    mat[i][i] = 1;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      Mint a = mat[j][i];
      for (int k = 0; k < n; ++k) {
        mat[j][k] -= a * mat[i][k];
        inv[j][k] -= a * inv[i][k];
      }
    }
  }
  return inv;
}
