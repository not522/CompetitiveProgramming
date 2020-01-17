#pragma once
#include "container.hpp"

#include <unordered_map>

template <typename T, typename S>
class UnorderedMap : public Container<std::unordered_map<T, S>> {
public:
  UnorderedMap() : Container<std::unordered_map<T, S>>() {}

  bool contains(const T &a) const { return this->count(a) != 0; }

  int count(const T &t) const { return std::unordered_map<T, S>::count(t); }
};
