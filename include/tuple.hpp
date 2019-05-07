#pragma once
#include "template.hpp"

#include <tuple>

template <typename... T> class Tuple : public std::tuple<T...> {
public:
  Tuple(Input &in) : std::tuple<T...>() { (void)in; }
};

template <typename T, typename... S>
class Tuple<T, S...> : public std::tuple<T, S...> {
public:
  Tuple() : std::tuple<T, S...>() {}

  Tuple(T t, S... s) : std::tuple<T, S...>(t, s...) {}

  Tuple(const std::tuple<T, S...> &t) : std::tuple<T, S...>(t) {}

  Tuple(Input &in) {
    auto a = std::tuple<T>(in);
    std::tuple<S...> b = Tuple<S...>(in);
    std::tuple<T, S...> c = std::tuple_cat(a, b);
    *this = c;
  }

  template <int n> auto &get() { return std::get<n>(*this); }

  template <int n> const auto &get() const { return std::get<n>(*this); }
};

template <typename... T> Tuple<T...> makeTuple(const T &... args) {
  return Tuple<T...>(args...);
}

namespace std {
template <typename... T>
class tuple_size<Tuple<T...>>
    : public std::integral_constant<size_t, sizeof...(T)> {};
template <std::size_t I, typename... T> class tuple_element<I, Tuple<T...>> {
public:
  using type = tuple_element_t<I, std::tuple<T...>>;
};
} // namespace std
