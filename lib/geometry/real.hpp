#pragma once
#include "arithmetic.hpp"
#include "ordered.hpp"

class Real : public Arithmetic<Real>, public arithmetic::Modulus<Real>, public Ordered<Real> {
private:
  static long double EPS;
  long double val;

public:
  Real() {}

  Real(long double val) : val(val) {}

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

  template<typename T> Real operator%=(const T& r) {
    long double v = static_cast<long double>(r);
    val -= floor(val / v) * v;
    return *this;
  }
  
  template<typename T> bool operator<(const T r) const {
    return val < static_cast<long double>(r) - EPS;
  }

  operator long double() const {
    return val;
  }
};

long double Real::EPS = 1e-8;

inline ostream& operator<<(ostream& os, const Real& a) {
  stringstream ss;
	ss << fixed << setprecision(15) << (long double)a;
  os << ss.str();
  return os;
}

inline istream& operator>>(istream& is, Real& a) {
	long double n;
	is >> n;
	a = n;
	return is;
}
