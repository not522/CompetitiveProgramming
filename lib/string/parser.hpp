#pragma once
#include "string/to_integer.hpp"

template<typename T = long long> class Parser {
private:
  string s;
  int p;
  vector<map<char, function<T(T, T)>>> ope;

  T term() {
    if (s[p] == '(') {
      ++p;
      T res = expr(0);
      ++p;
      return res;
    }
    string res = "";
    for (; isdigit(s[p]); ++p) res += s[p];
    return toInteger<T>(res);
  }

  T expr(int level) {
    if (level == (int)ope.size()) return term();
    T res = expr(level + 1);
    for (char c; c = s[p++], ope[level].count(c);) res = ope[level][c](res, expr(level + 1));
    --p;
    return res;
  }

public:
  void addOperator(function<T(T, T)> func, char c, int level) {
    if ((int)ope.size() <= level) ope.resize(level + 1);
    ope[level][c] = func;
  }

  long long parse(const string& s) {
    this->s = s + '@';
    p = 0;
    return expr(0);
  }
};

template<typename T = long long> inline T parse(const string& s) {
  Parser<T> parser;
  parser.addOperator(plus<T>(), '+', 0);
  parser.addOperator(minus<T>(), '-', 0);
  parser.addOperator(multiplies<T>(), '*', 1);
  parser.addOperator(divides<T>(), '/', 1);
  return parser.parse(s);
}
