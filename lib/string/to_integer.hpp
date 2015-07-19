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
