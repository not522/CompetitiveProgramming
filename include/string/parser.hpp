#pragma once
#include "string.hpp"
#include "unordered_map.hpp"

template <typename T> struct Digit {
  T operator()(String &s, int &p) {
    if (!isdigit(s[p])) {
      throw "empty term";
    }
    if (s[p] == '0' && p + 1 < int(s.size()) && !isdigit(s[p + 1])) {
      throw "leading zeros";
    }
    String res;
    for (; isdigit(s[p]); ++p) {
      res += s[p];
    }
    return T(res);
  }
};

template <typename T> struct LeadingZeros {
  T operator()(String &s, int &p) {
    if (!isdigit(s[p])) {
      throw "empty term";
    }
    String res;
    for (; isdigit(s[p]); ++p) {
      res += s[p];
    }
    return T(res);
  }
};

template <typename T = int64_t, typename Lexer = Digit<T>> class Parser {
private:
  String s;
  int p;
  UnorderedMap<char, std::function<T(T)>> unary_operator;
  Vector<UnorderedMap<char, std::function<T(T, T)>>> binary_operator;
  UnorderedMap<char, char> brackets;

  T term() {
    if (brackets.contains(s[p])) {
      const char end = brackets[s[p]];
      ++p;
      T res = expr(0);
      if (s[p] != end) {
        throw "mismatch brackets";
      }
      ++p;
      return res;
    }
    if (unary_operator.contains(s[p])) {
      auto f = unary_operator[s[p]];
      ++p;
      return f(term());
    }
    Lexer lexer;
    return lexer(s, p);
  }

  T expr(int level) {
    if (level == binary_operator.size()) {
      return term();
    }
    T res = expr(level + 1);
    for (char c; c = s[p++], binary_operator[level].contains(c);) {
      res = binary_operator[level][c](res, expr(level + 1));
    }
    --p;
    return res;
  }

public:
  void addUnaryOperator(std::function<T(T)> func, char c) {
    unary_operator[c] = func;
  }

  void addBinaryOperator(std::function<T(T, T)> func, char c, int level) {
    if (binary_operator.size() <= level) {
      binary_operator.resize(level + 1);
    }
    binary_operator[level][c] = func;
  }

  void addBrackets(char begin, char end) { brackets[begin] = end; }

  int64_t parse(const String &s) {
    this->s = s;
    p = 0;
    return expr(0);
  }
};

template <typename T = int64_t> T parse(const String &s) {
  Parser<T> parser;
  parser.addUnaryOperator([](T t) { return +t; }, '+');
  parser.addUnaryOperator(std::negate<T>(), '-');
  parser.addBinaryOperator(std::plus<T>(), '+', 0);
  parser.addBinaryOperator(std::minus<T>(), '-', 0);
  parser.addBinaryOperator(std::multiplies<T>(), '*', 1);
  parser.addBinaryOperator(std::divides<T>(), '/', 1);
  parser.addBrackets('(', ')');
  return parser.parse(s);
}
