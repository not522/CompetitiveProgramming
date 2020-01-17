#pragma once
#include "license.hpp"

#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>

using std::cerr;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::swap;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName(std::string t, std::string f) : t(t), f(f) {}
  std::string do_truename() const { return t; }
  std::string do_falsename() const { return f; }
};

void setBoolName(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

struct Initializer {
  Initializer() {
    cout << std::fixed << std::setprecision(15) << std::boolalpha;
    setBoolName("Yes", "No");
  }
} initializer;

struct Input {
  bool eof;

  Input() : eof(false) {}

  operator char() {
    char v;
    while (!(this->eof = (std::scanf("%c", &v) != 1)) && std::isspace(v)) {
    }
    return v;
  }

  operator int() {
    int v;
    this->eof = (std::scanf("%d", &v) != 1);
    return v;
  }

  operator long() {
    long v;
    this->eof = (std::scanf("%ld", &v) != 1);
    return v;
  }

  operator long long() {
    long long v;
    this->eof = (std::scanf("%lld", &v) != 1);
    return v;
  }

  operator unsigned int() {
    unsigned int v;
    this->eof = (std::scanf("%u", &v) != 1);
    return v;
  }

  operator unsigned long() {
    unsigned long v;
    this->eof = (std::scanf("%lu", &v) != 1);
    return v;
  }

  operator unsigned long long() {
    unsigned long long v;
    this->eof = (std::scanf("%llu", &v) != 1);
    return v;
  }

  operator double() {
    double v;
    this->eof = (std::scanf("%lf", &v) != 1);
    return v;
  }

  operator long double() {
    long double v;
    this->eof = (std::scanf("%Lf", &v) != 1);
    return v;
  }

  void ignore() const { getchar(); }
} in;

template <typename T> T abs(T a) { return a >= 0 ? a : -a; }

template <typename T, typename S> bool chmin(T &a, const S &b) {
  return a > b ? a = b, true : false;
}

template <typename T, typename S> bool chmax(T &a, const S &b) {
  return a < b ? a = b, true : false;
}

template <typename T, typename S> std::function<S(T)> cast() {
  return [](const T &t) { return static_cast<S>(t); };
}

template <typename T> T copy(const T &a) { return T(a); }

class ZeroPadding {
public:
  ZeroPadding(int n) : n(n) {}

  int n;
};

std::ostream &operator<<(std::ostream &os, const ZeroPadding &z) {
  os << std::setw(z.n) << std::setfill('0');
  return os;
}

template <typename T> constexpr T inf() {
  return std::numeric_limits<T>::max() / 2 - 1;
}
