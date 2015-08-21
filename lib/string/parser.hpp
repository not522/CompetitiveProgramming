#pragma once
#include "string/to_integer.hpp"

template<typename T = long long> class Parser {
private:
  string s;
  int p;
  unordered_map<char, function<T(T)>> unary_operator;
  vector<unordered_map<char, function<T(T, T)>>> binary_operator;
  unordered_map<char, char> brackets;

  T term() {
    if (brackets.count(s[p])) {
      const char end = brackets[s[p]];
      ++p;
      T res = expr(0);
      if (s[p] != end) throw "mismatch brackets";
      ++p;
      return res;
    }
    if (unary_operator.count(s[p])) {
      auto f = unary_operator[s[p]];
      ++p;
      return f(term());
    }
    // TODO check term is valid or not
    string res;
    for (; isdigit(s[p]); ++p) res += s[p];
    return toInteger<T>(res);
  }

  T expr(size_t level) {
    if (level == binary_operator.size()) return term();
    T res = expr(level + 1);
    for (char c; c = s[p++], binary_operator[level].count(c);) res = binary_operator[level][c](res, expr(level + 1));
    --p;
    return res;
  }

public:
  void addUnaryOperator(function<T(T)> func, char c) {
    unary_operator[c] = func;
  }

  void addBinaryOperator(function<T(T, T)> func, char c, size_t level) {
    if (binary_operator.size() <= level) binary_operator.resize(level + 1);
    binary_operator[level][c] = func;
  }

  void addBrackets(char begin, char end) {
    brackets[begin] = end;
  }

  long long parse(const string& s) {
    this->s = s + '@';
    p = 0;
    return expr(0);
  }
};

template<typename T = long long> inline T parse(const string& s) {
  Parser<T> parser;
  parser.addUnaryOperator([](T t){return +t;}, '+');
  parser.addUnaryOperator(negate<T>(), '-');
  parser.addBinaryOperator(plus<T>(), '+', 0);
  parser.addBinaryOperator(minus<T>(), '-', 0);
  parser.addBinaryOperator(multiplies<T>(), '*', 1);
  parser.addBinaryOperator(divides<T>(), '/', 1);
  parser.addBrackets('(', ')');
  return parser.parse(s);
}
