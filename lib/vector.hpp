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

template<typename T> bool next_permutation(vector<T>& v) {
  return next_permutation(v.begin(), v.end());
}

template<typename T> int lower_bound(vector<T>& v, T t) {
  return lower_bound(v.begin(), v.end(), t) - v.begin();
}

template<typename T> int upper_bound(vector<T>& v, T t) {
  return upper_bound(v.begin(), v.end(), t) - v.begin();
}

template<typename T> T accumulate(vector<T>& v) {
  return accumulate(v.begin(), v.end(), T(0));
}

template<typename T> void partial_sum(vector<T>& v, vector<T>& u) {
  partial_sum(v.begin(), v.end(), u.begin());
}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {
  return inner_product(v.begin(), v.end(), u.begin(), T(0));
}
