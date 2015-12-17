#pragma once
#include "ordered.hpp"
#include "math/vector.hpp"

template<typename T> class Matrix : public arithmetic::Addition<Matrix<T>>, public arithmetic::Subtraction<Matrix<T>>, public Ordered<Matrix<T>> {
protected:
  vector<Vector<T>> val;

public:
  Matrix(int n, int m) : val(n, Vector<T>(m)) {}

  Vector<T>& operator[](int n) {return val[n];}

  Matrix operator+=(const Matrix& m) {
    for (int i = 0; i < (int)val.size(); ++i) val[i] += m[i];
    return *this;
  }

  Matrix operator-=(const Matrix& m) {
    for (int i = 0; i < (int)val.size(); ++i) val[i] -= m[i];
    return *this;
  }

  Matrix operator*=(const Matrix& _m) {
    Matrix &m = const_cast<Matrix&>(_m);
    Matrix res(size(), m[0].size());
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < m.size(); ++j) {
        for (int k = 0; k < m[0].size(); ++k) {
          res[i][k] += val[i][j] * m[j][k]; 
        }
      }
    }
    return *this = res;
  }

  Matrix operator*(const Matrix& m) const {
    Matrix res = *this;
    return res *= m;
  }

  Vector<T> operator*(const Vector<T>& v) {
    Vector<T> res(size());
    for (int i = 0; i < size(); ++i) res[i] += val[i] * v;
    return res;
  }

  bool operator<(const Matrix& m) const {
    if (size() != m.size()) return size() < m.size();
    for (int i = 0; i < size(); ++i) if (val[i] != m.val[i]) return val[i] < m.val[i];
    return false;
  }

  int size() const {
    return val.size();
  }
};
