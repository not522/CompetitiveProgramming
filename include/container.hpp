#pragma once
#include "template.hpp"

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
    std::vector<S> v(n, in);
    *this = Container<T>(v.begin(), v.end());
  }

  bool in(const S& a) const {
    return find(this->begin(), this->end(), a) != this->end();
  }
};
