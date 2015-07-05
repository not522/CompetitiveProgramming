#pragma once
#include "arithmetic.hpp"

template<typename T> class Vector : public arithmetic::Addition<Vector<T>>, public arithmetic::Subtraction<Vector<T>> {
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

  T operator*(const Vector& v) const {
    return inner_product(val.begin(), val.end(), const_cast<Vector&>(v).begin(), T(0));
  }

  int size() const {
    return val.size();
  }

  typename vector<T>::const_iterator begin() const {
    return val.begin();
  }

  typename vector<T>::const_iterator end() const {
    return val.end();
  }
};
