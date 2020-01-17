#pragma once
#include "string.hpp"

Vector<int> find_all(const String &s1, const String &s2) {
  Vector<int> res;
  auto pos = s1.find(s2);
  while (pos != String::npos) {
    res.emplace_back(pos);
    pos = s1.find(s2, pos + 1);
  }
  return res;
}
