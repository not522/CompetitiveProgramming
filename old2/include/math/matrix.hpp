#pragma once
#include "arithmetic.hpp"
#include "vector.hpp"

template <typename T, typename S>
class MatrixBase : public Vector<Vector<S>>,
                   public IndivisibleArithmetic<MatrixBase<T, S>> {
public:
  MatrixBase(int n, int m) : Vector<Vector<S>>(n, Vector<S>(m)) {}

  template <typename V> T &operator*=(const V &m) {
    T res(this->size(), m[0].size());
    for (int i = 0; i < this->size(); ++i) {
      for (int j = 0; j < m.size(); ++j) {
        for (int k = 0; k < m[0].size(); ++k) {
          res[i][k] += (*this)[i][j] * m[j][k];
        }
      }
    }
    *this = res;
    return static_cast<T &>(*this);
  }

  template <typename V> T operator*(const V &m) const {
    return copy(*this) *= m;
  }

  Vector<S> operator*(const Vector<S> &v) {
    Vector<S> res(this->size());
    for (int i = 0; i < this->size(); ++i) {
      res[i] += (*this)[i].inner_product(v);
    }
    return res;
  }
};

template <typename T> class Matrix : public MatrixBase<Matrix<T>, T> {
public:
  Matrix(int n, int m) : MatrixBase<Matrix<T>, T>(n, m) {}
};
