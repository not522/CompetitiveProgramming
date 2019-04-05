#pragma once
#include "vector.hpp"

#include <string>

class String : public std::string {
public:
  String() : std::string() {}

  String(char c) : std::string(1, c) {}

  String(int n) : std::string(std::to_string(n)) {}

  String(long n) : std::string(std::to_string(n)) {}

  String(long long n) : std::string(std::to_string(n)) {}

  String(const char *s) : std::string(s) {}

  String(const std::string& s) : std::string(s) {}

  String(Input& in) {
    std::cin >> *this;
    in.eof = std::cin.eof();
  }

  static String getline() {
    String v;
    std::getline(std::cin, v);
    in.eof = std::cin.eof();
    return v;
  }

  String reverse() {
    std::reverse(this->begin(), this->end());
    return *this;
  }

  Vector<String> split(char delim = ' ') const {
    std::stringstream ss(*this);
    Vector<String> res;
    for (std::string tmp; std::getline(ss, tmp, delim);) {
      if (tmp != "") res.emplace_back(tmp);
    }
    return res;
  }

  String toupper() {
    for (auto &c : *this) {
      c = std::toupper(c);
    }
    return *this;
  }

  String tolower() {
    for (auto &c : *this) {
      c = std::tolower(c);
    }
    return *this;
  }

  template<typename Function> String transform(Function func) const {
    String res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  bool contains(const String& s) const {
    cerr << s << endl;
    return this->find(s) != std::string::npos;
  }

  String erase(char c) {
    String res;
    for (char i : *this) {
      if (i != c) {
        res += i;
      }
    }
    return *this = res;
  }

  int size() const { return std::string::size(); }

  operator int() const { return std::stoi(*this); }

  operator long double() const { return std::stold(*this); }
};
