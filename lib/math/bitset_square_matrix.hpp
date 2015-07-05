#pragma once
#include "arithmetic.hpp"
#include "container/bitset.hpp"

class BitsetSquareMatrix : public Arithmetic<BitsetSquareMatrix> {
private:
  vector<Bitset> val;

public:
  BitsetSquareMatrix(size_t Nb) : val(Nb, Bitset(Nb)) {}

  Bitset& operator[](int n) {
    return val[n];
  }
	
	BitsetSquareMatrix operator+=(const BitsetSquareMatrix& m) {
    for (size_t i = 0; i < size(); ++i) val[i] ^= const_cast<BitsetSquareMatrix&>(m)[i];
		return *this;
	}
	
	BitsetSquareMatrix operator-=(const BitsetSquareMatrix& m) {
    for (size_t i = 0; i < size(); ++i) val[i] ^= const_cast<BitsetSquareMatrix&>(m)[i];
		return *this;
	}

  BitsetSquareMatrix operator*=(const BitsetSquareMatrix& _m) {
    BitsetSquareMatrix m = _m.transpose(), res(size());
    for (size_t i = 0; i < size(); ++i) res[i] = *this * m[i];
    return *this = res.transpose();
  }

	BitsetSquareMatrix operator/=(const BitsetSquareMatrix& m) {
		return *this *= m.inverse();
	}

  BitsetSquareMatrix operator*(const BitsetSquareMatrix& m) const {
    auto res(static_cast<const BitsetSquareMatrix&>(*this));
    return res *= m;
  }

  Bitset operator*(const Bitset& v) const {
    Bitset res(size());
    for (size_t i = 0; i < size(); ++i) res[i] = (val[i] & v).parity();
    return res;
  }

  BitsetSquareMatrix transpose() const {
    BitsetSquareMatrix res(size());
    for (size_t i = 0; i < size(); ++i) {
      for (size_t j = 0; j < size(); ++j) {
        res[i][j] = const_cast<BitsetSquareMatrix&>(*this)[j][i];
      }
    }
    return res;
  }

  size_t size() const {
    return val.size();
  }

  BitsetSquareMatrix identity() const {
    BitsetSquareMatrix res(size());
    for (size_t i = 0; i < size(); ++i) res[i][i] = true;
    return res;
  }

  BitsetSquareMatrix inverse() const {
    size_t n = size();
    BitsetSquareMatrix mat = *this;
    BitsetSquareMatrix inv = identity();
    for (size_t i = 0; i < n; ++i) {
      int p = i;
      for (size_t j = i + 1; j < n; ++j) {
        if (abs(mat[j][i]) > abs(mat[p][i])) p = j;
      }
      swap(mat[i], mat[p]);
      swap(inv[i], inv[p]);
      for (size_t j = 0; j < n; ++j) {
        if (i == j) continue;
        if (!mat[j][i]) continue;
        mat[j] ^= mat[i];
        inv[j] ^= inv[i];
      }
    }
    return inv;
  }
};
