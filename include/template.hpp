#pragma once
#include "license.hpp"

#include <algorithm>
#include <cassert>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>

using std::abs;
using std::cerr;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::numeric_limits;
using std::swap;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName (std::string t, std::string f) : t(t), f(f) {}
  std::string do_truename() const {return t;}
  std::string do_falsename() const {return f;}
};

void set_bool_name(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

struct Initializer {
  Initializer() {
    cout << std::fixed << std::setprecision(15) << std::boolalpha;
    set_bool_name("Yes", "No");
  }
} initializer;

struct Input {
  bool eof;

  Input() : eof(false) {}

  operator char() {
    char v;
    this->eof = (std::scanf("%c", &v) != 1);
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

  void ignore() const {
    getchar();
  }
} in;

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}

template<typename T, typename S> std::function<S(T)> cast() {
  return [](const T& t) { return static_cast<S>(t); };
}
