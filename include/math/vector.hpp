#pragma once
#include "ordered.hpp"
#include "arithmetic.hpp"

template<typename T> class Vector : public Addition<Vector<T>>, public Subtraction<Vector<T>>, public Ordered<Vector<T>> {
protected:
  vector<T> val;

public:
  Vector(int n) : val(n, 0) {}

  T& operator[](int n) {return val[n];}

  T operator[](int n) const {return val[n];}

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

  bool operator<(const Vector& v) const {
    if (size() != v.size()) return size() < v.size();
    for (int i = 0; i < size(); ++i) if (val[i] != v.val[i]) return val[i] < v.val[i];
    return false;
  }

  int size() const {return val.size();}

  typename vector<T>::const_iterator begin() const {return val.begin();}

  typename vector<T>::const_iterator end() const {return val.end();}
};
