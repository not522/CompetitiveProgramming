#pragma once
#include "math/matrix.hpp"

template<typename T> class SquareMatrix : public Matrix<T> {
public:
  SquareMatrix(int n) : Matrix<T>(n, n) {}

  SquareMatrix(const Matrix<T>& m) : Matrix<T>(m) {}

	SquareMatrix operator/=(SquareMatrix& m) {
		return *this *= m.inverse();
	}

  SquareMatrix operator/(SquareMatrix m) {
    return *this * m.inverse();
  }

  SquareMatrix identity() const {
    SquareMatrix res(this->size());
    for (int i = 0; i < this->size(); ++i) res[i][i] = 1;
    return res;
  }

  SquareMatrix inverse() const {
    int n = this->size();
    SquareMatrix mat = *this;
    SquareMatrix inv = identity();
    for (int i = 0; i < n; ++i) {
      int p = i;
      for (int j = i + 1; j < n; ++j) {
        if (abs(mat[j][i]) > abs(mat[p][i])) p = i;
      }
      swap(mat[i], mat[p]);
      swap(inv[i], inv[p]);
      for (int j = i + 1; j < n; ++j) mat[i][j] /= mat[i][i];
      for (int j = 0; j < n; ++j) inv[i][j] /= mat[i][i];
      for (int j = i + 1; j < n; ++j) {
        for (int k = i + 1; k < n; ++k) mat[j][k] -= mat[j][i] * mat[i][k];
        for (int k = 0; k < n; ++k) inv[j][k] -= mat[j][i] * inv[i][k];
      }
    }
    return inv;
  }
};