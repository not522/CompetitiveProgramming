#pragma once
#include "arithmetic.hpp"
#include "ordered.hpp"
#include "math/basic.hpp"

class Real : public Arithmetic<Real>, public Ordered<Real> {
private:
  long double val;

public:
  static long double EPS;

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

  template<typename T> Real operator-(const T& v) const {return Real(*this) -= v;}

  template<typename T> Real operator*(const T& v) const {return Real(*this) *= v;}

  template<typename T> Real operator/(const T& v) const {return Real(*this) /= v;}

  template<typename T> bool operator<(const T r) const {return val < static_cast<long double>(r) - EPS;}

  Real abs() const {return std::abs(val);}

  Real sqrt() const {return std::sqrt(val);}

  Real floor() const {return std::floor(val);}

  operator long double() const {return val;}
};

long double Real::EPS = 1e-10;

std::ostream& operator<<(std::ostream& os, const Real& a) {
  os << static_cast<long double>(a);
  return os;
}
