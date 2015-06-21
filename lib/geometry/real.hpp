#pragma once
#include "template.hpp"

class Real {
private:
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
	
	Real operator+(const Real& m) const {
		Real res = *this;
		res += m;
		return res;
	}
	
	Real operator-(const Real& m) const {
		Real res = *this;
		res -= m;
		return res;
	}
	
	Real operator*(const Real& m) const {
		Real res = *this;
		res *= m;
		return res;
	}
	
	Real operator/(const Real& m) const {
		Real res = *this;
		res /= m;
		return res;
	}
  
  operator long double() {
    return val;
  }
};

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
