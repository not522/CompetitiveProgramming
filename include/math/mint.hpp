#pragma once
#include "arithmetic.hpp"
#include "math/inverse.hpp"

class Mint : public Arithmetic<Mint> {
private:
  static long long mod;
  static Inverse inverse;
  long long val;

public:
  Mint() : val(0) {}

  Mint(const long long& val) {
    this->val = val % mod;
    if (this->val < 0) this->val += mod;
  }

  static void setMod(const long long& m) {
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

  operator long long() {return val;}

  Mint identity() const {return 1;}
};

long long Mint::mod = 1000000007;
Inverse Mint::inverse(1000000007);

ostream& operator<<(ostream& os, Mint a) {
  os << (long long)a;
  return os;
}

istream& operator>>(istream& is, Mint& a) {
  long long n;
  is >> n;
  a = n;
  return is;
}