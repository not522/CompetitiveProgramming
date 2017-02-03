#pragma once
#include "template.hpp"

template<bool Repeat = false> void replaceAll(string& str, const string& from, const string& to) {
  for (size_t pos = 0; (pos = str.find(from, pos)) != string::npos;) {
    str.replace(pos, from.size(), to);
    if (!Repeat) pos += to.size();
  }
}
