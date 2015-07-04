#pragma once
#include "arithmetic.hpp"
#include "ordered.hpp"

class Real : public Arithmetic<Real>, public Ordered<Real> {
private:
  static long double EPS;
  long double val;

public:
  Real() {}

  Real(long double val) : val(val) {}

  Real operator+=(const Real& r) {
    val += r.val;
    return *this;
  }
  
  Real operator-=(const Real& r) {
    val -= r.val;
    return *this;
  }
  
  Real operator*=(const Real& r) {
    val *= r.val;
    return *this;
  }
  
  Real operator/=(const Real& r) {
    val /= r.val;
    return *this;
  }

  bool operator==(Real r) const {
    return *this <= r && r <= *this;
  }

  bool operator<(Real r) const {
    return val < r.val - EPS;
  }

  operator long double() {
    return val;
  }
};

long double Real::EPS = 1e-8;

ostream& operator<<(ostream& os, Real a) {
	os << (long double)a;
	return os;
}

istream& operator>>(istream& is, Real& a) {
	long double n;
	is >> n;
	a = n;
	return is;
}
