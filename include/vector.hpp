#pragma once
#include "arithmetic.hpp"
#include "container.hpp"
#include "ordered.hpp"

#include <vector>

template<typename T> class Vector : public Container<std::vector<T>>, public Arithmetic<Vector<T>>, public Modulus<Vector<T>>, public Ordered<Vector<T>> {
public:
  Vector() = default;

  Vector(const Vector<T>& v) = default;

  Vector(int n) : Container<std::vector<T>>(n) {}

  Vector(int n, T t) : Container<std::vector<T>>(n, t) {}

  template<typename Itr> Vector(Itr first, Itr last) : Container<std::vector<T>>(first, last) {}

  Vector(const std::initializer_list<T>& v) : Container<std::vector<T>>(v) {}

  Vector(int n, std::istream& cin) : Container<std::vector<T>>(n, cin) {}

  Vector operator+=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] += v[i];
    return *this;
  }

  Vector operator+=(const T& v) {
    for (auto& i : *this) {
      i += v;
    }
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

  void partial_sort(int k, bool reverse = false) {
    if (!reverse) {
      std::partial_sort(this->begin(), this->begin() + k, this->end());
    } else {
      std::partial_sort(this->begin(), this->begin() + k, this->end(), std::greater<T>());
    }
  }

  void sort() {
    std::sort(this->begin(), this->end());
  }

  void rsort() {
    std::sort(this->rbegin(), this->rend());
  }

  Vector<T> subvector(int a) const {
    return Vector<T>(this->begin(), this->begin() + a);
  }

  Vector<T> subvector(int a, int b) const {
    return Vector<T>(this->begin() + a, this->begin() + b);
  }

  template<typename Function> auto transform(Function func) const -> Vector<decltype(func(T()))> {
    Vector<decltype(func(T()))> res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> partial_sum() const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  Vector<T> reverse() const {
    Vector<T> res = *this;
    std::reverse(res.begin(), res.end());
    return res;
  }

  template<typename Function> bool all_of(Function func) {
    return std::all_of(this->begin(), this->end(), func);
  }

  Vector<T> adjacent_difference() const {
    Vector<T> res;
    std::adjacent_difference(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  T max() const {
    return *max_element(this->begin(), this->end());
  }

  T min() const {
    return *min_element(this->begin(), this->end());
  }

  int argmax() const {
    return max_element(this->begin(), this->end()) - this->begin();
  }

  int argmin() const {
    return min_element(this->begin(), this->end()) - this->begin();
  }
};

template<typename T> Vector<T> iota(int n) {
  Vector<T> v(n);
  std::iota(v.begin(), v.end(), T(0));
  return v;
}
