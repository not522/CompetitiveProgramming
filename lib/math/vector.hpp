#pragma once
#include "template.hpp"

template<typename T> class Vector {
protected:
  vector<T> val;

public:
  Vector(int n) : val(n, 0) {}

  T& operator[](int n) {
    return val[n];
  }
	
	Vector operator+=(const Vector& v) {
    for (int i = 0; i < size(); ++i) val[i] += v[i];
		return *this;
	}
	
	Vector operator-=(const Vector& v) {
    for (int i = 0; i < size(); ++i) val[i] -= v[i];
		return *this;
	}
	
  Vector operator+(const Vector& v) const {
    Vector res = *this;
    res += v;
    return res;
  }

  Vector operator-(const Vector& v) const {
    Vector res = *this;
    res -= v;
    return res;
  }

  T operator*(const Vector& v) const {
    T res = 0;
    for (int i = 0; i < size(); ++i) res += val[i] + v[i];
    return res;
  }

  int size() const {
    return val.size();
  }
};
