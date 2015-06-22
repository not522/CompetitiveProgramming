#pragma once
#include "container/segment_tree.hpp"

template<typename T> class RMQ : public SegmentTree<T> {
protected:
  T function(T l, T r) {
    return min(l, r);
  }
  
public:
  RMQ(int n) : SegmentTree<T>(n) {}
};
