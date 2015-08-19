#pragma once
#include "math/bitset_matrix.hpp"

class BitsetSquareMatrix : public BitsetMatrix {
public:
  BitsetSquareMatrix(int n) : BitsetMatrix(n, n) {}

  BitsetSquareMatrix(const BitsetMatrix& m) : BitsetMatrix(m) {}

  BitsetSquareMatrix operator/=(const BitsetSquareMatrix& m) {
		return *this *= m.inverse();
	}

  BitsetSquareMatrix identity() const {
    BitsetSquareMatrix res(size());
    for (int i = 0; i < size(); ++i) res[i][i] = true;
    return res;
  }

  BitsetSquareMatrix inverse() const {
    int n = size();
    BitsetSquareMatrix mat = *this;
    BitsetSquareMatrix inv = identity();
    for (int i = 0; i < n; ++i) {
      int p = i;
      for (int j = i + 1; j < n; ++j) {
        if (abs(mat[j][i]) > abs(mat[p][i])) p = j;
      }
      swap(mat[i], mat[p]);
      swap(inv[i], inv[p]);
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (!mat[j][i]) continue;
        mat[j] ^= mat[i];
        inv[j] ^= inv[i];
      }
    }
    return inv;
  }
};
