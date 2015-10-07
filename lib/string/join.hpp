#pragma once
#include "template.hpp"

string join(const vector<string> &v, char delim = ' ') {
  string res;
  for (const auto& s : v) res += delim + s;
  return res.substr(1);
}
