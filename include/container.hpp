#pragma once
#include "template.hpp"

#include <algorithm>
#include <vector>

template<typename T> class Container : public T {
private:
  using S = typename T::value_type;
  using Itr = typename T::iterator;

public:
  Container() : T() {}

  Container(int n) : T(n) {}

  Container(int n, S s) : T(n, s) {}

  template<typename Itr> Container(Itr first, Itr last) : T(first, last) {}

  Container(const std::initializer_list<S>& v) : T(v) {}

  Container(int n, Input& in) {
    std::vector<S> v(n);
    for (auto& i : v) {
      i = in;
    }
    *this = Container<T>(v.begin(), v.end());
  }

  S max() const {
    return *max_element(this->begin(), this->end());
  }

  template<typename Function> auto max(Function func) const {
    std::vector<std::pair<decltype(func(S())), S>> res;
    for (const auto &i : *this) {
      res.emplace_back(func(i), i);
    }
    return max_element(res.begin(), res.end())->second;
  }

  S min() const {
    return *min_element(this->begin(), this->end());
  }

  template<typename Function> auto min(Function func) const {
    std::vector<std::pair<decltype(func(S())), S>> res;
    for (const auto &i : *this) {
      res.emplace_back(func(i), i);
    }
    return min_element(res.begin(), res.end())->second;
  }

  int argmax() const {
    return max_element(this->begin(), this->end()) - this->begin();
  }

  int argmin() const {
    return min_element(this->begin(), this->end()) - this->begin();
  }

  bool contains(const S& a) const {
    return find(this->begin(), this->end(), a) != this->end();
  }

  int size() const { return T::size(); }

  std::pair<Itr, Itr> equal_range(const S &a) {
    return std::equal_range(this->begin(), this->end(), a);
  }

  template<typename Function> bool all_of(Function func) const {
    return std::all_of(this->begin(), this->end(), func);
  }

  template<typename Function> bool any_of(Function func) const {
    return std::any_of(this->begin(), this->end(), func);
  }

  template<typename Function> bool none_of(Function func) const {
    return std::none_of(this->begin(), this->end(), func);
  }

  int count(const S &s) const {
    return std::count(this->begin(), this->end(), s);
  }
};
