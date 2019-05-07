#pragma once
#include "container.hpp"

#include <unordered_map>

template <typename T, typename S>
class UnorderedMap : public Container<std::unordered_map<T, S>> {
public:
  UnorderedMap() : Container<std::unordered_map<T, S>>() {}

  bool contains(const T &a) const { return this->find(a) != this->end(); }
};
