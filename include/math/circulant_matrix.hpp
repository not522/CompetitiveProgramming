#pragma once
#include "math/square_matrix.hpp"

// store val[i] as val[i + j][j]
template <typename T> class CirculantMatrix : public Vector<T> {
public:
  CirculantMatrix(int n) : Vector<T>(n) {}

  CirculantMatrix &operator*=(const CirculantMatrix &m) {
    int n = this->size();
    CirculantMatrix res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res[i + j >= n ? i + j - n : i + j] += (*this)[i] * m[j];
      }
    }
    *this = res;
    return *this;
  }

  CirculantMatrix operator*(const CirculantMatrix &m) const {
    auto res = *this;
    res *= m;
    return res;
  }

  // TODO FFT
  CirculantMatrix &operator/=(const CirculantMatrix &m) {
    int n = this->size();
    SquareMatrix<T> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i + j >= n ? i + j - n : i + j][j] = (*this)[i];
        b[i + j >= n ? i + j - n : i + j][j] = m[i];
      }
    }
    a /= b;
    for (int i = 0; i < n; ++i) {
      (*this)[i] = a[i][0];
    }
    return *this;
  }

  CirculantMatrix operator/(const CirculantMatrix &m) const {
    auto res = *this;
    res /= m;
    return res;
  }

  // TODO FFT
  Vector<T> operator*(const Vector<T> &v) const {
    int n = this->size();
    Vector<T> res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res[i] += (*this)[i - j < 0 ? i - j + n : i - j] * v[j];
      }
    }
    return res;
  }

  static CirculantMatrix identity(int n) {
    CirculantMatrix res(n);
    res[0] = 1;
    return res;
  }
};
