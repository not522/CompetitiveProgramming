#pragma once
#include "container.hpp"

#include <map>

template<typename T, typename S> class Map : public Container<std::map<T, S>> {
public:
  Map() : Container<std::map<T, S>>() {}
};
