#pragma once
#include "arithmetic.hpp"
#include "math/basic.hpp"
#include "ordered.hpp"

template <typename T>
class Fraction : public Arithmetic<Fraction<T>>, public Ordered<Fraction<T>> {
public:
  T n, d;

  Fraction() {}

  Fraction(T n) : n(n), d(1) {}

  Fraction(T n, T d) : n(n), d(d) { normalize(); }

  void normalize() {
    T g = gcd(n, d);
    n /= g;
    d /= g;
  }

  Fraction &operator+=(const Fraction &f) {
    n = n * f.d + f.n * d;
    d *= f.d;
    normalize();
    return *this;
  }

  Fraction &operator-=(const Fraction &f) {
    n = n * f.d - f.n * d;
    d *= f.d;
    normalize();
    return *this;
  }

  Fraction &operator*=(const Fraction &f) {
    n *= f.n;
    d *= f.d;
    normalize();
    return *this;
  }

  Fraction &operator/=(const Fraction &f) {
    n *= f.d;
    d *= f.n;
    normalize();
    return *this;
  }

  bool operator<(const Fraction &f) const { return n * f.d < f.n * d; }
};

template <typename T>
ostream &operator<<(ostream &os, const Fraction<T> &fraction) {
  os << fraction.n << " " << fraction.d;
  return os;
}

template <typename T> istream &operator>>(istream &is, Fraction<T> &fraction) {
  T n, d;
  is >> n >> d;
  fraction = Fraction<T>(n, d);
  return is;
}
