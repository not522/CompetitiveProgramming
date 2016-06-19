#pragma once
#include "template.hpp"

template<typename T> inline istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> inline ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

template<typename T> inline T min(vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> inline T max(vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> inline void sort(vector<T>& v) {sort(v.begin(), v.end());}

template<typename T, typename Function> inline void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> inline void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> inline void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> inline void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> inline void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> inline bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> inline int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T> inline int in(vector<T> v, T t) {return find(v, t) != (int)v.size();}

template<typename T> inline int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> inline int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> inline T accumulate(const vector<T>& v) {return accumulate(v.begin(), v.end(), T(0));}

template<typename T> inline void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> inline void partial_sum(vector<T>& v, vector<T>& u) {partial_sum(v.begin(), v.end(), u.begin());}

template<typename T> inline T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T, typename Function> inline int count_if(vector<T> v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> inline void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> inline bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}
