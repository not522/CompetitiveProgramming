#pragma once
#include "ordered.hpp"
#include "vector.hpp"

template <typename T> class Matrix : public Vector<Vector<T>> {
public:
  Matrix(int n, int m) : Vector<Vector<T>>(n, Vector<T>(m)) {}

  Matrix operator+=(const Matrix &m) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] += m[i];
    }
    return *this;
  }

  Matrix operator+(const Matrix &m) {
    auto res = *this;
    return res += m;
  }

  Matrix operator-=(const Matrix &m) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] -= m[i];
    }
    return *this;
  }

  Matrix operator-(const Matrix &m) {
    auto res = *this;
    return res -= m;
  }

  Matrix operator*=(const Matrix &_m) {
    Matrix &m = const_cast<Matrix &>(_m);
    Matrix res(this->size(), m[0].size());
    for (int i = 0; i < this->size(); ++i) {
      for (int j = 0; j < m.size(); ++j) {
        for (int k = 0; k < m[0].size(); ++k) {
          res[i][k] += (*this)[i][j] * m[j][k];
        }
      }
    }
    return *this = res;
  }

  Matrix operator*(const Matrix &m) const {
    Matrix res = *this;
    return res *= m;
  }

  Vector<T> operator*(const Vector<T> &v) {
    Vector<T> res(this->size());
    for (int i = 0; i < this->size(); ++i) {
      res[i] += (*this)[i].inner_product(v);
    }
    return res;
  }
};
