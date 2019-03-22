#pragma once
#include "vector.hpp"

#include <string>

class String : public std::string {
public:
  String() : std::string() {}

  String(int n) : std::string(std::to_string(n)) {}

  String(const char *s) : std::string(s) {}

  String(const std::string& s) : std::string(s) {}

  String(Input& in) {
    (void)in;
    std::cin >> *this;
  }

  static String getline() {
    String v;
    std::getline(std::cin, v);
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

  String toupper() const {
    auto s = *this;
    for (auto &c : s) {
      c = std::toupper(c);
    }
    return s;
  }

  template<typename Function> String transform(Function func) const {
    String res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  bool in(const String& s) const {
    return this->find(s) != std::string::npos;
  }

  operator int() const {return std::stoi(*this);}

  operator long double() const {return std::stold(*this);}
};
