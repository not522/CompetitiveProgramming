#pragma once
#include "template.hpp"

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

template<typename T> T min(vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> T max(vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> int min_element(vector<T>& v) {return min_element(v.begin(), v.end()) - v.begin();}

template<typename T> int max_element(vector<T>& v) {return max_element(v.begin(), v.end()) - v.begin();}

template<typename T> void sort(vector<T>& v) {sort(v.begin(), v.end());}

template<typename T, typename Function> void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T> int in(vector<T> v, T t) {return find(v, t) != (int)v.size();}

template<typename T> int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> T accumulate(const vector<T>& v, function<T(T, T)> func = plus<T>()) {return accumulate(v.begin(), v.end(), T(), func);}

template<typename T> void adjacent_difference(vector<T>& v) {adjacent_difference(v.begin(), v.end(), v.begin());}

template<typename T> void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> void partial_sum(vector<T>& v, vector<T>& u) {partial_sum(v.begin(), v.end(), u.begin());}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T> int count(const vector<T>& v, T t) {return count(v.begin(), v.end(), t);}

template<typename T, typename Function> int count_if(const vector<T>& v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}

template<typename T> vector<T> subvector(vector<T>& v, int a, int b) {return vector<T>(v.begin() + a, v.begin() + b);}

template<typename T> int kinds(const vector<T>& v) {return set<T>(v.begin(), v.end()).size();}

template<typename T> void iota(vector<T>& v) {iota(v.begin(), v.end(), T());}

template<typename T> bool is_sorted(const vector<T>& v) {return is_sorted(v.begin(), v.end());}
