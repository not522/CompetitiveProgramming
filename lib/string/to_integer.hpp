#pragma once
#include "template.hpp"

template<typename T = long long> T toInteger(const string&);

template<> int toInteger<int>(const string& s) {
  return stoi(s);
}

template<> long toInteger<long>(const string& s) {
  return stol(s);
}

template<> long long toInteger<long long>(const string& s) {
  return stoll(s);
}

template<typename T = long long> T toInteger(const string& s, int n) {
  T res = 0;
  for (char c : s) {
    if (isdigit(c)) res = res * n + c - '0';
    else if (isalpha(c)) res = res * n + tolower(c) - 'a' + 10;
  }
  return s[0] == '-' ? -res : res;
}
