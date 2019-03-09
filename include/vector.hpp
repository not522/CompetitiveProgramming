#pragma once
#include "arithmetic.hpp"
#include "container.hpp"
#include "ordered.hpp"

template<typename T> class Vector : public Container<std::vector<T>>, public Arithmetic<Vector<T>>, public Modulus<Vector<T>>, public Ordered<Vector<T>> {
public:
  Vector() = default;

  Vector(const Vector<T>& v) = default;

  Vector(int n) : Container<std::vector<T>>(n) {}

  Vector(int n, T t) : Container<std::vector<T>>(n, t) {}

  template<typename Itr> Vector(Itr first, Itr last) : Container<std::vector<T>>(first, last) {}

  Vector(int n, std::istream& cin) : Container<std::vector<T>>(n, cin) {}

  Vector operator+=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] += v[i];
    return *this;
  }

  Vector operator-=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] -= v[i];
    return *this;
  }

  Vector operator*=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] *= v[i];
    return *this;
  }

  Vector operator/=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] /= v[i];
    return *this;
  }

  Vector operator%=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] %= v[i];
    return *this;
  }

  bool operator<(const Vector& v) const {
    if (this->size() != v.size()) return this->size() < v.size();
    for (unsigned i = 0; i < this->size(); ++i) {
      if ((*this)[i] != v[i]) {
        return (*this)[i] < v[i];
      }
    }
    return false;
  }

  T inner_product(const Vector<T>& v) const {
    return std::inner_product(this->begin(), this->end(), v.begin(), T(0));
  }

  void output(char sep = '\n', char end = '\n') const {
    if (!this->empty()) {
      cout << (*this)[0];
    }
    for (unsigned i = 1; i < this->size(); ++i) {
      cout << sep << (*this)[i];
    }
    cout << end;
  }

  template<typename Function> void partial_sort(int k, Function func) {
    std::partial_sort(this->begin(), this->begin() + k, this->end(), func);
  }

  void sort() {
    std::sort(this->begin(), this->end());
  }

  Vector<T> subvector(int a) const {
    return Vector<T>(this->begin(), this->begin() + a);
  }
};
