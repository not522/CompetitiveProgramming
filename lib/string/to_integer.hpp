#pragma once
#include "template.hpp"

template<typename T> inline T toInteger(const string&);

template<> inline int toInteger<int>(const string& s) {
  return stoi(s);
}

template<> inline long toInteger<long>(const string& s) {
  return stol(s);
}

template<> inline long long toInteger<long long>(const string& s) {
  return stoll(s);
}

template<typename T = long long> inline T toInteger(const string& s, int n) {
  T res = 0;
  for (char c : s) {
    if (isdigit(c)) res = res * n + c - '0';
    else if (isalpha(c)) res = res * n + tolower(c) - 'a' + 10;
  }
  return s[0] == '-' ? -res : res;
}
