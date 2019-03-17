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
using std::cin;
using std::cout;
using std::endl;
using std::hypot;
using std::max;
using std::min;
using std::numeric_limits;
using std::swap;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName (std::string t = "Yes", std::string f = "No") : t(t), f(f) {}
  std::string do_truename() const {return t;}
  std::string do_falsename() const {return f;}
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    std::ios::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(15) << std::boolalpha;
    cout.imbue(std::locale(cout.getloc(), new BoolName));
  }
} initializer;

void set_bool_name(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}

template<typename T, typename S> std::function<S(T)> cast() {
  return [](const T& t) { return static_cast<S>(t); };
}
