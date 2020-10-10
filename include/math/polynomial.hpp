#pragma once
#include "math/fft.hpp"
#include "math/pow.hpp"
#include "vector.hpp"

template <typename T> class Polynomial : public Vector<T> {
private:
  void normalize() {
    while (this->size() > 1 && this->back() == 0) {
      this->pop_back();
    }
    if (this->empty()) {
      this->emplace_back(0);
    }
  }

public:
  Polynomial() { normalize(); }

  Polynomial(const Vector<T> &v) : Vector<T>(v) { normalize(); }

  Polynomial(const int n) : Vector<T>(n) {}

  Polynomial(const int n, const T val) : Vector<T>(n, val) {}

  Polynomial(const std::initializer_list<T> &v) : Vector<T>(v) {}

  Polynomial(const int n, Input &in) : Vector<T>(n, in) {}

  Polynomial &operator+=(const T &t) {
    for (auto &v : *this) {
      v += t;
    }
    return *this;
  }

  Polynomial &operator-=(const T &t) {
    for (auto &v : *this) {
      v -= t;
    }
    return *this;
  }

  Polynomial &operator*=(const T &t) {
    for (auto &v : *this) {
      v *= t;
    }
    return *this;
  }

  Polynomial &operator/=(const T &t) {
    for (auto &v : *this) {
      v /= t;
    }
    return *this;
  }

  Polynomial &operator%=(const T &t) {
    for (auto &v : *this) {
      v %= t;
    }
    return *this;
  }

  Polynomial &operator+=(const Polynomial &p) {
    for (int i = 0; i < p.size(); ++i) {
      if (int(this->size()) == i) {
        this->emplace_back(p[i]);
      } else {
        (*this)[i] += p[i];
      }
    }
    normalize();
    return *this;
  }

  Polynomial &operator-=(const Polynomial &p) {
    for (int i = 0; i < p.size(); ++i) {
      if (int(this->size()) == i) {
        (*this).emplace_back(-p[i]);
      } else {
        (*this)[i] -= p[i];
      }
    }
    normalize();
    return *this;
  }

  Polynomial &operator*=(const Polynomial &p) {
    int a = this->size(), b = p.size();
    if (min(a, b) <= 256) {
      Polynomial res(a + b - 1);
      for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
          res[i + j] += (*this)[i] * p[j];
        }
      }
      *this = res;
      normalize();
      return *this;
    }
    int m = (max(a, b) + 1) / 2;
    Polynomial a0(m), a1(m), b0(m), b1(m);
    for (int i = 0; i < min(m, a); ++i) {
      a0[i] = (*this)[i];
    }
    for (int i = m; i < a; ++i) {
      a1[i - m] = (*this)[i];
    }
    for (int i = 0; i < min(m, b); ++i) {
      b0[i] = p[i];
    }
    for (int i = m; i < b; ++i) {
      b1[i - m] = p[i];
    }
    auto z0 = a0 * b0, z2 = a1 * b1, z1 = z0 + z2 - (a1 - a0) * (b1 - b0);
    *this = Vector<T>(a + b);
    for (int i = 0; i < z0.size(); ++i) {
      (*this)[i] += z0[i];
    }
    for (int i = 0; i < z1.size(); ++i) {
      (*this)[i + m] += z1[i];
    }
    for (int i = 0; i < z2.size(); ++i) {
      (*this)[i + 2 * m] += z2[i];
    }
    normalize();
    return *this;
  }

  Polynomial &operator/=(const Polynomial &p) {
    Polynomial res(this->size() - p.size() + 1);
    for (int i = this->size() - p.size(); i >= 0; --i) {
      res[i] = (*this)[p.size() + i - 1] / p.back();
      for (int j = 0; j < p.size(); ++j) {
        (*this)[i + j] -= res[i] * p[j];
      }
    }
    *this = res;
    normalize();
    return *this;
  }

  Polynomial &operator%=(const Polynomial &p) {
    for (int i = int(this->size()) - int(p.size()); i >= 0; --i) {
      T d = (*this)[p.size() + i - 1] / p.back();
      for (int j = 0; j < p.size(); ++j) {
        (*this)[i + j] -= d * p[j];
      }
    }
    normalize();
    return *this;
  }

  template <typename S> T operator()(const S &s) const {
    T res = 0;
    for (int i = 0; i < this->size(); ++i) {
      res += (*this)[i] * pow(s, i);
    }
    return res;
  }

  Polynomial &integrate() {
    Polynomial res(this->size() + 1);
    for (int i = 0; i < this->size(); ++i) {
      res[i + 1] = (*this)[i] / (i + 1);
    }
    *this = res;
    normalize();
    return *this;
  }

  Polynomial &differentiate() {
    Polynomial res(this->size() - 1);
    for (int i = 1; i < this->size(); ++i) {
      res[i - 1] = i * (*this)[i];
    }
    return *this = res;
  }

  static constexpr Polynomial identity() { return Polynomial(1, 1); }
};
