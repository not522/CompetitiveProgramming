#pragma once
#include "math/square_matrix.hpp"

// store val[i] as val[i + j][j]
template<typename T> class CirculantMatrix : public Vector<T> {
public:
  CirculantMatrix(int n) : Vector<T>(n) {}
  
  CirculantMatrix operator*(CirculantMatrix& m) {
    int n = this->size();
    CirculantMatrix res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res[i + j >= n ? i + j - n : i + j] += this->val[i] * m[j];
      }
    }
    return res;
  }

  CirculantMatrix operator*=(CirculantMatrix& m) {
    return *this = *this * m;
  }
  
  // TODO FFT
	CirculantMatrix operator/=(CirculantMatrix& m) {
    int n = this->size();
    SquareMatrix<T> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i + j >= n ? i + j - n : i + j][j] = (*this)[i];
        b[i + j >= n ? i + j - n : i + j][j] = m[i];
      }
    }
    a /= b;
    for (int i = 0; i < n; ++i) (*this)[i] = a[i][0];
    return *this;
	}

  CirculantMatrix operator/(CirculantMatrix m) {
    CirculantMatrix res = *this;
    res /= m;
    return res;
  }

  // TODO FFT
  Vector<T> operator*(Vector<T>& v) {
    int n = this->size();
    Vector<T> res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) res[i] += (*this)[i - j < 0 ? i - j + n : i - j] * v[j];
    }
    return res;
  }

  CirculantMatrix identity() const {
    CirculantMatrix res(this->size());
    res[0] = 1;
    return res;
  }
};
