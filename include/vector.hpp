#pragma once
#include "container.hpp"

template<typename T> class Vector : public Container<vector<T>> {
public:
  Vector(int n) : Container<vector<T>>(n) {}

  Vector(int n, istream& cin) : Container<vector<T>>(n, cin) {}
};

template<typename T> T min(const vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> T max(const vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> int min_element(vector<T>& v) {return min_element(v.begin(), v.end()) - v.begin();}

template<typename T> int max_element(vector<T>& v) {return max_element(v.begin(), v.end()) - v.begin();}

template<typename T, typename Function> void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T, typename S> int in(T v, S t) {return find(v.begin(), v.end(), t) != v.end();}

template<typename T> int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T, typename S = typename T::value_type, typename BinaryOperation> S accumulate(const T& v, S init, BinaryOperation func) {
  return accumulate(v.begin(), v.end(), init, func);
}

template<typename T, typename S = typename T::value_type> S accumulate(const T& v, S init = 0) {
  return accumulate(v.begin(), v.end(), init);
}

template<typename T> void adjacent_difference(vector<T>& v) {adjacent_difference(v.begin(), v.end(), v.begin());}

template<typename T> void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> vector<T> partial_sum(const vector<T>& v) {
  vector<T> u(v.size());
  partial_sum(v.begin(), v.end(), u.begin());
  return u;
}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T> int count(const T& v, typename T::value_type t) {return count(v.begin(), v.end(), t);}

template<typename T, typename Function> int count_if(const vector<T>& v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> bool all_of(vector<T> v, Function func) {return all_of(v.begin(), v.end(), func);}

template<typename T, typename Function> bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}

template<typename T, typename Function> bool none_of(vector<T> v, Function func) {return none_of(v.begin(), v.end(), func);}

template<typename T> vector<T> subvector(vector<T>& v, int a, int b) {return vector<T>(v.begin() + a, v.begin() + b);}

template<typename T> int kinds(const T& v) {return set<typename T::value_type>(v.begin(), v.end()).size();}

template<typename T> map<typename T::value_type, int> count_kinds(const T& v) {
  map<typename T::value_type, int> res;
  for (const auto& i : v) ++res[i];
  return res;
}

template<typename T> void iota(vector<T>& v, T t = 0) {iota(v.begin(), v.end(), t);}

template<typename T> bool is_sorted(const vector<T>& v) {return is_sorted(v.begin(), v.end());}
