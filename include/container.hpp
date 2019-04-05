#pragma once
#include "template.hpp"

#include <algorithm>
#include <vector>

template<typename T> class Container : public T {
private:
  using S = typename T::value_type;

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
};
