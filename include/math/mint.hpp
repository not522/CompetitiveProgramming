#pragma once
#include "arithmetic.hpp"
#include "math/inverse.hpp"

class Mint : public Arithmetic<Mint> {
private:
  static int64_t mod;
  static Inverse inverse;
  int64_t val;

public:
  Mint() : val(0) {}

  Mint(const int64_t& val) {
    this->val = val % mod;
    if (this->val < 0) this->val += mod;
  }

  static void setMod(const int64_t& m) {
    mod = m;
    inverse = Inverse(m);
  }

  Mint operator+=(const Mint& m) {
    val += m.val;
    if (val >= mod) val -= mod;
    return *this;
  }

  Mint operator-=(const Mint& m) {
    val -= m.val;
    if (val < 0) val += mod;
    return *this;
  }

  Mint operator*=(const Mint& m) {
    val *= m.val;
    val %= mod;
    return *this;
  }

  Mint operator/=(const Mint& m) {
    val *= inverse(m.val);
    val %= mod;
    return *this;
  }

  Mint operator++() {return *this += 1;}

  Mint operator--() {return *this -= 1;}

  operator int64_t() {return val;}

  Mint identity() const {return 1;}
};

int64_t Mint::mod = 1000000007;
Inverse Mint::inverse(1000000007);

ostream& operator<<(ostream& os, Mint a) {
  os << int64_t(a);
  return os;
}

istream& operator>>(istream& is, Mint& a) {
  int64_t n;
  is >> n;
  a = n;
  return is;
}
