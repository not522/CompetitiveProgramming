#pragma once
#include "map.hpp"
#include "ordered.hpp"

#include <numeric>

template <typename T> class Vector : public Container<std::vector<T>> {
public:
  Vector() = default;

  Vector(const Vector<T> &v) = default;

  Vector(int n) : Container<std::vector<T>>(n) {}

  Vector(int n, T t) : Container<std::vector<T>>(n, t) {}

  template <typename Itr>
  Vector(Itr first, Itr last) : Container<std::vector<T>>(first, last) {}

  Vector(const std::initializer_list<T> &v) : Container<std::vector<T>>(v) {}

  Vector(int n, Input &in) : Container<std::vector<T>>(n, in) {}

  Vector &operator+=(const Vector &v) {
    if (this->size() < v.size()) {
      this->resize(v.size());
    }
    for (int i = 0; i < v.size(); ++i) {
      (*this)[i] += v[i];
    }
    return *this;
  }

  Vector &operator+=(const T &v) {
    for (auto &i : *this) {
      i += v;
    }
    return *this;
  }

  Vector &operator-=(const Vector &v) {
    if (this->size() < v.size()) {
      this->resize(v.size());
    }
    for (int i = 0; i < v.size(); ++i) {
      (*this)[i] -= v[i];
    }
    return *this;
  }

  Vector &operator-=(const T &v) {
    for (auto &i : *this) {
      i -= v;
    }
    return *this;
  }

  Vector &operator*=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] *= v[i];
    }
    return *this;
  }

  Vector &operator*=(const T &v) {
    for (auto &i : *this) {
      i *= v;
    }
    return *this;
  }

  Vector &operator/=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] /= v[i];
    }
    return *this;
  }

  Vector &operator/=(const T &v) {
    for (auto &i : *this) {
      i /= v;
    }
    return *this;
  }

  Vector &operator%=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] %= v[i];
    }
    return *this;
  }

  Vector &operator%=(const T &v) {
    for (auto &i : *this) {
      i %= v;
    }
    return *this;
  }

  Vector operator+(const Vector &v) const { return Vector(*this) += v; }

  Vector operator+(const T &v) const { return Vector(*this) += v; }

  Vector operator-(const Vector &v) const { return Vector(*this) -= v; }

  Vector operator-(const T &v) const { return Vector(*this) -= v; }

  Vector operator*(const Vector &v) const { return Vector(*this) *= v; }

  Vector operator*(const T &v) const { return Vector(*this) *= v; }

  Vector operator/(const Vector &v) const { return Vector(*this) /= v; }

  Vector operator/(const T &v) const { return Vector(*this) /= v; }

  Vector operator%(const Vector &v) const { return Vector(*this) %= v; }

  Vector operator%(const T &v) const { return Vector(*this) %= v; }

  Vector operator-() const { return *this * -1; }

  T inner_product(const Vector<T> &v) const {
    return std::inner_product(this->begin(), this->end(), v.begin(), T(0));
  }

  Vector<T> &partial_sort(int k, bool reverse = false) {
    if (!reverse) {
      std::partial_sort(this->begin(), this->begin() + k, this->end());
    } else {
      std::partial_sort(this->begin(), this->begin() + k, this->end(),
                        std::greater<T>());
    }
    return *this;
  }

  Vector<T> &sort() {
    std::sort(this->begin(), this->end());
    return *this;
  }

  template <typename Function> Vector<T> &sort(Function func) {
    std::sort(this->begin(), this->end(), func);
    return *this;
  }

  Vector<T> &rsort() {
    std::sort(this->rbegin(), this->rend());
    return *this;
  }

  Vector<int> argsort() const {
    Vector<Tuple<T, int>> v;
    for (int i = 0; i < this->size(); ++i) {
      v.emplace_back((*this)[i], i);
    }
    v.sort();
    auto f = [](const Tuple<T, int> &t) { return t.template get<1>(); };
    return v.transform(f);
  }

  Vector<T> &nth_element(int n, bool reverse = false) {
    if (!reverse) {
      std::nth_element(this->begin(), this->begin() + n, this->end());
    } else {
      std::nth_element(this->begin(), this->begin() + n, this->end(),
                       std::greater<T>());
    }
    return *this;
  }

  Vector<T> subvector(int a) const {
    return Vector<T>(this->begin(), this->begin() + a);
  }

  Vector<T> subvector(int a, int b) const {
    return Vector<T>(this->begin() + a, this->begin() + b);
  }

  template <typename Function> auto transform(Function func) const {
    Vector<decltype(func(T()))> res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> partial_sum() const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  template <typename Function> Vector<T> partial_sum(Function func) const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> &reverse() {
    std::reverse(this->begin(), this->end());
    return *this;
  }

  template <typename Function> int count_if(Function func) const {
    return std::count_if(this->begin(), this->end(), func);
  }

  Vector<T> adjacent_difference() const {
    Vector<T> res;
    std::adjacent_difference(this->begin(), this->end(),
                             std::back_inserter(res));
    return res;
  }

  T lower_bound(T t) const {
    return std::lower_bound(this->begin(), this->end(), t) - this->begin();
  }

  T upper_bound(T t) const {
    return std::upper_bound(this->begin(), this->end(), t) - this->begin();
  }

  T accumulate() const {
    return std::accumulate(this->begin(), this->end(), T());
  }

  template <typename S, typename Function>
  S accumulate(S n, Function func) const {
    return std::accumulate(this->begin(), this->end(), n, func);
  }

  template <typename Int> static Vector<T> makeVector(Int n) {
    return Vector<T>(n);
  }

  template <typename Int> static Vector<T> makeVector(Input &in, Int n) {
    return Vector<T>(n, in);
  }

  template <typename Int, typename... Ints>
  static auto makeVector(Input &in, Int n, Ints... ints) {
    Vector<decltype(makeVector(in, ints...))> res;
    for (int i = 0; i < n; ++i) {
      res.emplace_back(makeVector(in, ints...));
    }
    return res;
  }

  template <typename Int, typename... Ints>
  static auto makeVector(Int n, Ints... ints) {
    Vector<decltype(makeVector(ints...))> res;
    for (int i = 0; i < n; ++i) {
      res.emplace_back(makeVector(ints...));
    }
    return res;
  }

  Vector<T> &unique() {
    this->erase(std::unique(this->begin(), this->end()), this->end());
    return *this;
  }

  bool next_permutation() {
    return std::next_permutation(this->begin(), this->end());
  }

  Vector<T> &rotate(int n) {
    std::rotate(this->begin(), this->begin() + n, this->end());
    return *this;
  }

  Map<T, int> countAll() const {
    Map<T, int> res;
    for (const auto &i : *this) {
      ++res[i];
    }
    return res;
  }

  T matmul(const T &a) const {
    return this->transform([&](const T &i) { return i.inner_product(a); });
  }
};

template <typename T> Vector<T> iota(int n, T m = 0) {
  Vector<T> v(n);
  std::iota(v.begin(), v.end(), m);
  return v;
}

template <typename T, typename S> void read(Vector<T> &t, Vector<S> &s) {
  for (int i = 0; i < t.size(); ++i) {
    t[i] = T(in);
    s[i] = S(in);
  }
}

template <typename T, typename S, typename U>
void read(Vector<T> &t, Vector<S> &s, Vector<U> &u) {
  for (int i = 0; i < t.size(); ++i) {
    t[i] = T(in);
    s[i] = S(in);
    u[i] = U(in);
  }
}

template <typename T> Vector<T> operator+(const T &a, const Vector<T> &b) {
  return b + a;
}

template <typename T> Vector<T> operator-(const T &a, const Vector<T> &b) {
  return -b + a;
}

template <typename T> Vector<T> operator*(const T &a, const Vector<T> &b) {
  return b * a;
}
