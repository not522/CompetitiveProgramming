#pragma once
#include "template.hpp"

template<typename T = int64_t> T toInteger(const string&);

template<> int toInteger<int>(const string& s) {
  return stoi(s);
}

template<> int64_t toInteger<int64_t>(const string& s) {
  return stoll(s);
}

template<typename T = int64_t> T toInteger(const string& s, int n) {
  T res = 0;
  for (char c : s) {
    if (isdigit(c)) res = res * n + c - '0';
    else if (isalpha(c)) res = res * n + tolower(c) - 'a' + 10;
  }
  return s[0] == '-' ? -res : res;
}
