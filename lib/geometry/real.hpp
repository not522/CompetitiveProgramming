#pragma once
#include "arithmetic.hpp"
#include "ordered.hpp"
#include "math/basic.hpp"

class Real : public Arithmetic<Real>, public Modulus<Real>, public Ordered<Real> {
private:
  long double val;

  operator long double() const {return val;}

public:
  static long double EPS;
  static int precision;

  Real() {}

  Real(long double val) : val(val) {}

  Real operator-() const {return -val;}

  template<typename T> Real operator+=(const T& r) {
    val += static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator-=(const T& r) {
    val -= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator*=(const T& r) {
    val *= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator/=(const T& r) {
    val /= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator%=(const T& r) {return *this = mod(*this, static_cast<Real>(r));}

  template<typename T> Real operator-(const T& v) const {return Real(*this) -= v;}

  template<typename T> Real operator*(const T& v) const {return Real(*this) *= v;}

  template<typename T> Real operator/(const T& v) const {return Real(*this) /= v;}

  template<typename T> bool operator<(const T r) const {return val < static_cast<long double>(r) - EPS;}

  Real abs() const {return std::abs(val);}

  Real sqrt() const {return std::sqrt(val);}

  long double toLongDouble() const {return val;}
};

long double Real::EPS = 1e-10;
int Real::precision = 15;

inline ostream& operator<<(ostream& os, const Real& a) {
  os << fixed << setprecision(Real::precision) << a.toLongDouble();
  return os;
}

inline istream& operator>>(istream& is, Real& a) {
  long double n;
  is >> n;
  a = n;
  return is;
}

Real floor(const Real& r) {
  return floor(r.toLongDouble());
}
