#pragma once
#include "arithmetic.hpp"
#include "container/bitset.hpp"

class BitsetMatrix : public IndivisibleArithmetic<BitsetMatrix> {
private:
  vector<Bitset> val;

public:
  BitsetMatrix(int n) : val(n) {}

  BitsetMatrix(int n, int m) : val(n, Bitset(m)) {}

  Bitset& operator[](int n) {return val[n];}

  const Bitset& operator[](int n) const {return val[n];}

  BitsetMatrix operator+=(const BitsetMatrix& m) {
    for (int i = 0; i < size(); ++i) val[i] ^= m[i];
    return *this;
  }

  BitsetMatrix operator-=(const BitsetMatrix& m) {
    for (int i = 0; i < size(); ++i) val[i] ^= m[i];
    return *this;
  }

  BitsetMatrix operator*=(const BitsetMatrix& _m) {
    BitsetMatrix m = _m.transpose(), res(size());
    for (int i = 0; i < size(); ++i) res[i] = *this * m[i];
    return *this = res.transpose();
  }

  BitsetMatrix operator*(const BitsetMatrix& m) const {
    auto res(static_cast<const BitsetMatrix&>(*this));
    return res *= m;
  }

  Bitset operator*(const Bitset& v) const {
    Bitset res(size());
    for (int i = 0; i < size(); ++i) res[i] = (val[i] & v).parity();
    return res;
  }

  BitsetMatrix transpose() const {
    BitsetMatrix res(size());
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < size(); ++j) {
        res[i][j] = (*this)[j][i];
      }
    }
    return res;
  }

  int size() const {return val.size();}

  int rank() const {
    int n = 0, r = 0;
    BitsetMatrix mat = *this;
    for (int i = 0; i < size(); ++i) n = max(n, mat[i].size());
    for (int i = 0; i < n; ++i) {
      int p = r;
      for (int j = r + 1; j < size(); ++j) if (abs(mat[j][i]) > abs(mat[p][i])) p = j;
      if (mat[p][i] == 0) continue;
      swap(mat[r], mat[p]);
      for (int j = r + 1; j < size(); ++j) {
        if (!mat[j][i]) continue;
        mat[j] ^= mat[r];
      }
      ++r;
      if (r == size()) break;
    }
    return r;
  }
};
