#pragma once
#include "math/vector.hpp"

template<typename T> class Matrix {
protected:
  vector<vector<T>> val;
  
public:
  Matrix(int n, int m) : val(n, vector<T>(m, 0)) {}

  vector<T>& operator[](int n) {
    return val[n];
  }
	
	Matrix operator+=(const Matrix& m) {
    for (int i = 0; i < (int)val.size(); ++i) val[i] += m[i];
		return *this;
	}
	
	Matrix operator-=(const Matrix& m) {
    for (int i = 0; i < (int)val.size(); ++i) val[i] -= m[i];
		return *this;
	}

  Matrix operator*=(Matrix m) {
    return *this = *this * m;
  }

  Matrix operator+(const Matrix& m) const {
    Matrix res = *this;
    res += m;
    return res;
  }

  Matrix operator-(const Matrix& m) const {
    Matrix res = *this;
    res -= m;
    return res;
  }

  Matrix operator*(Matrix m) {
    Matrix res(size(), m[0].size());
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < m.size(); ++j) {
        for (int k = 0; k < m[0].size(); ++k) {
          res[i][k] += val[i][j] * m[j][k]; 
        }
      }
    }
    return res;
  }
  
  Vector<T> operator*(Vector<T>& v) {
    Vector<T> res(size());
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < v.size(); ++j) res[i] += val[i][j] * v[j];
    }
    return res;
  }

  int size() const {
    return val.size();
  }
};