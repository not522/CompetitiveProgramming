#pragma once
#include "template.hpp"

void replaceAll(string& str, const string& from, const string& to) {
  for (size_t pos = 0; (pos = str.find(from, pos)) != string::npos; pos += to.size()) {
    str.replace(pos, from.size(), to);
  }
}
