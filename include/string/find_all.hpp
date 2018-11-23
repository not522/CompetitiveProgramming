#pragma once
#include "template.hpp"

vector<int> find_all(const string &s1, const string& s2) {
  vector<int> res;
  auto pos = s1.find(s2);
  while (pos != string::npos) {
    res.emplace_back(pos);
    pos = s1.find(s2, pos + 1);
  }
  return res;
}
