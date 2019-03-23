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

  Mint(Input &in) : val(in) {
    this->val = this->val % mod;
    if (this->val < 0) this->val += mod;
  }

  static void setMod(const int64_t& m) {
    mod = m;
    inverse = Inverse(m);
  }

  Mint operator-() const { return Mint(val ? mod - val : 0); }

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

  template<typename T> Mint operator-(const T& m) { return Arithmetic<Mint>::operator-(m); }

  explicit operator char() const { return val; }

  explicit operator int() const { return val; }

  explicit operator int64_t() const { return val; }

  Mint identity() const {return 1;}
};

int64_t Mint::mod = 1000000007;
Inverse Mint::inverse(1000000007);

std::ostream& operator<<(std::ostream& os, Mint a) {
  os << int64_t(a);
  return os;
}

Mint operator+(const int& n, const Mint& m) { return m + n; }
Mint operator-(const int& n, const Mint& m) { return -m + n; }
Mint operator*(const int& n, const Mint& m) { return m * n; }
Mint operator/(const int& n, const Mint& m) { return Mint(n) / m; }

Mint operator+(const int64_t& n, const Mint& m) { return m + n; }
Mint operator-(const int64_t& n, const Mint& m) { return -m + n; }
Mint operator*(const int64_t& n, const Mint& m) { return m * n; }
Mint operator/(const int64_t& n, const Mint& m) { return Mint(n) / m; }
