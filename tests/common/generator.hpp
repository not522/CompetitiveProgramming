#pragma once
#include "testlib.h"
#include <functional>
#include <boost/any.hpp>

using namespace std;
using namespace boost;

void generate(string title, function<void(stringstream&)> func, int mx = 20) {
  for (int i = 0; i < mx; ++i) {
    stringstream ss;
    func(ss);
    string id = string(to_string(mx - 1).size() - to_string(i).size(), '0') + to_string(i);
    ofstream ofs((title + id + ".in").c_str());
    ofs << ss.str();
  }
}

bool next(map<string, int>& id, const map<string, vector<any>>& args) {
  for (const auto& itr : args) {
    ++id[itr.first];
    if (id[itr.first] < int(itr.second.size())) return true;
    id[itr.first] = 0;
  }
  return false;
}

void generate_combination(string title, function<void(stringstream&, const map<string, any>&)> func, const map<string, vector<any>>& args, int mx = 1) {
  map<string, int> index;
  int mx_ = mx;
  for (const auto& itr : args) {
    index[itr.first] = 0;
    mx_ *= itr.second.size();
  }
  for (int i = 0; ; ++i) {
    for (int j = 0; j < mx; ++j) {
      map<string, any> a;
      for (const auto& itr : args) a[itr.first] = itr.second[index[itr.first]];
      stringstream ss;
      func(ss, a);
      string id = string(to_string(mx_ - 1).size() - to_string(i * mx + j).size(), '0') + to_string(i * mx + j);
      ofstream ofs((title + id + ".in").c_str());
      ofs << ss.str();
    }
    if (!next(index, args)) break;
  }
}
