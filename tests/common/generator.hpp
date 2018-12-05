#pragma once
#include "testlib.h"
#include <functional>

using namespace std;

void generate(string title, function<void(stringstream&)> func, int mx = 20) {
  for (int i = 0; i < mx; ++i) {
    stringstream ss;
    func(ss);
    string id = string(to_string(mx - 1).size() - to_string(i).size(), '0') + to_string(i);
    ofstream ofs((title + id + ".in").c_str());
    ofs << ss.str();
  }
}
