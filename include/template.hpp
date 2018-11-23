#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct BoolName : numpunct<char> {
  string t, f;
  BoolName (string t = "Yes", string f = "No") : t(t), f(f) {}
  string do_truename() const {return t;}
  string do_falsename() const {return f;}
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
    cout.imbue(locale(cout.getloc(), new BoolName));
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

void set_bool_name(string t, string f) {
  cout.imbue(locale(cout.getloc(), new BoolName(t, f)));
}
