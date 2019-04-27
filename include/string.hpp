#pragma once
#include "vector.hpp"

#include <set>
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

  String(int n, char c) : std::string(n, c) {}

  String(Input& in) {
    std::cin >> *this;
    in.eof = std::cin.eof();
  }

  String operator+=(const String &s) {
    return *this = *this + s;
  }

  String operator+(const String &s) const {
    return std::operator+(*this, s);
  }

  String operator+=(char s) {
    return *this = *this + s;
  }

  String operator+(char s) const {
    return std::operator+(*this, s);
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

  int count(char c) const {
    return std::count(this->begin(), this->end(), c);
  }

  template<bool Repeat = false> String replaceAll(const String& from, const String& to) {
    for (size_t pos = 0; (pos = this->find(from, pos)) != std::string::npos;) {
      this->replace(pos, from.size(), to);
      if (!Repeat) pos += to.size();
    }
    return *this;
  }

  String sort() {
    std::sort(this->begin(), this->end());
    return *this;
  }

  String unique() {
    std::string::erase(std::unique(this->begin(), this->end()), this->end());
    return *this;
  }

  int size() const { return std::string::size(); }

  operator int() const { return std::stoi(*this); }

  operator long() const { return std::stol(*this); }

  operator long long() const { return std::stoll(*this); }

  operator float() const { return std::stof(*this); }

  operator double() const { return std::stod(*this); }

  operator long double() const { return std::stold(*this); }
};
