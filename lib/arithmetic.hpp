#include "template.hpp"

class Arithmetic {
public:
  virtual Arithmetic operator+=(const Arithmetic& a) {return a;};
  virtual Arithmetic operator-=(const Arithmetic& a) {return a;};
  virtual Arithmetic operator*=(const Arithmetic& a) {return a;};
  virtual Arithmetic operator/=(const Arithmetic& a) {return a;};
  
  Arithmetic operator+(const Arithmetic& a) const {
    Arithmetic res = *this;
    res += a;
    return res;
  }
  
  Arithmetic operator-(const Arithmetic& a) const {
    Arithmetic res = *this;
    res -= a;
    return res;
  }
  
  Arithmetic operator*(const Arithmetic& a) const {
    Arithmetic res = *this;
    res *= a;
    return res;
  }
  
  Arithmetic operator/(const Arithmetic& a) const {
    Arithmetic res = *this;
    res /= a;
    return res;
  }
};
