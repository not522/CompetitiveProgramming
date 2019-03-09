#pragma once
#include "template.hpp"

template<typename T> class Container : public T {
private:
  using S = typename T::value_type;

public:
  Container() : T() {}

  Container(int n) : T(n) {}

  template<typename Itr> Container(Itr first, Itr last) : T(first, last) {}

  Container(int n, istream& cin) {
    vector<S> v;
    for (int i = 0; i < n; ++i) {
      S a;
      cin >> a;
      v.emplace_back(a);
    }
    *this = Container<T>(v.begin(), v.end());
  }

  bool in(const S& a) const {
    return find(this->begin(), this->end(), a) != this->end();
  }
};