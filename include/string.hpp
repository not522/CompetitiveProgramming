#pragma once
#include "vector.hpp"

#include <string>

class String : public std::string {
public:
  constexpr static auto npos = std::string::npos;

  String() : std::string() {}

  String(char c) : std::string(1, c) {}

  String(int n) : std::string(std::to_string(n)) {}

  String(long n) : std::string(std::to_string(n)) {}

  String(long long n) : std::string(std::to_string(n)) {}

  String(const char *s) : std::string(s) {}

  String(const std::string &s) : std::string(s) {}

  String(int n, char c) : std::string(n, c) {}

  String(Input &in) {
    std::cin >> *this;
    in.eof = std::cin.eof();
  }

  String &operator+=(const String &s) { return *this = *this + s; }

  String operator+(const String &s) const { return std::operator+(*this, s); }

  String &operator+=(const char *s) { return *this = *this + s; }

  String operator+(const char *s) const { return std::operator+(*this, s); }

  String &operator+=(char s) { return *this = *this + s; }

  String operator+(char s) const { return std::operator+(*this, s); }

  String operator*(int n) const {
    String res;
    for (int i = 0; i < n; ++i) {
      res += *this;
    }
    return res;
  }

  static String getline() {
    String v;
    std::getline(std::cin, v);
    in.eof = std::cin.eof();
    return v;
  }

  String substr(size_t pos, size_t n_pos = std::string::npos) {
    return std::string::substr(pos, n_pos);
  }

  String &reverse() {
    std::reverse(this->begin(), this->end());
    return *this;
  }

  Vector<String> split(char delim = ' ') const {
    std::stringstream ss(*this);
    Vector<String> res;
    for (std::string tmp; std::getline(ss, tmp, delim);) {
      if (tmp != "") {
        res.emplace_back(tmp);
      }
    }
    return res;
  }

  String &toupper() {
    for (auto &c : *this) {
      c = std::toupper(c);
    }
    return *this;
  }

  String &tolower() {
    for (auto &c : *this) {
      c = std::tolower(c);
    }
    return *this;
  }

  template <typename Function> String transform(Function func) const {
    String res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  bool contains(const String &s) const {
    return this->find(s) != std::string::npos;
  }

  String &erase(char c) {
    String res;
    for (char i : *this) {
      if (i != c) {
        res += i;
      }
    }
    return *this = res;
  }

  int count(char c) const { return std::count(this->begin(), this->end(), c); }

  template <bool Repeat = false>
  String &replaceAll(const String &from, const String &to) {
    for (size_t pos = 0; (pos = this->find(from, pos)) != std::string::npos;) {
      this->replace(pos, from.size(), to);
      if (!Repeat) {
        pos += to.size();
      }
    }
    return *this;
  }

  String &sort() {
    std::sort(this->begin(), this->end());
    return *this;
  }

  String &rsort() {
    std::sort(this->rbegin(), this->rend());
    return *this;
  }

  String &unique() {
    std::string::erase(std::unique(this->begin(), this->end()), this->end());
    return *this;
  }

  String &rotate(int n) {
    std::rotate(this->begin(), this->begin() + n, this->end());
    return *this;
  }

  bool next_permutation() {
    return std::next_permutation(this->begin(), this->end());
  }

  template <typename T, typename Function1, typename Function2>
  T inner_product(const String &v, T init, Function1 func1,
                  Function2 func2) const {
    return std::inner_product(this->begin(), this->end(), v.begin(), init,
                              func1, func2);
  }

  template <typename Function> int find_if(Function func) const {
    return std::find_if(this->begin(), this->end(), func) - this->begin();
  }

  template <typename Function> bool all_of(Function func) const {
    return std::all_of(this->begin(), this->end(), func);
  }

  template <typename Function> bool any_of(Function func) const {
    return std::any_of(this->begin(), this->end(), func);
  }

  template <typename Function> bool none_of(Function func) const {
    return std::none_of(this->begin(), this->end(), func);
  }

  Vector<int> find_all(const String &s) const {
    Vector<int> res;
    auto pos = this->find(s);
    while (pos != String::npos) {
      res.emplace_back(pos);
      pos = this->find(s, pos + 1);
    }
    return res;
  }

  int size() const { return std::string::size(); }

  operator int() const { return std::stoi(*this); }

  operator long() const { return std::stol(*this); }

  operator long long() const { return std::stoll(*this); }

  operator float() const { return std::stof(*this); }

  operator double() const { return std::stod(*this); }

  operator long double() const { return std::stold(*this); }
};
