#pragma once
#include "template.hpp"

vector<string> split(const string &str, char delim){
  stringstream ss(str);
  vector<string> res;
  for (string tmp; getline(ss, tmp, delim);) res.push_back(tmp);
  return res;
}
