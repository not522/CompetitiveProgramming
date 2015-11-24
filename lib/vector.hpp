#pragma once
#include "template.hpp"

template <typename T> inline istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template <typename T> inline ostream& operator<<(ostream &s, const vector<T> &v) {
  for (T &t : v) s << t << endl;
  return s;
}

template<typename T> void sort(vector<T>& v) {
  sort(v.begin(), v.end());
}

template<typename T> void rsort(vector<T>& v) {
  sort(v.rbegin(), v.rend());
}

template<typename T> void reverse(vector<T>& v) {
  reverse(v.begin(), v.end());
}

template<typename T> void unique(vector<T>& v) {
  v.erase(unique(v.begin(), v.end()), v.end());
}
