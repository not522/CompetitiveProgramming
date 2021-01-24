#pragma once
#include "container/segment_tree.hpp"

template <typename T> class RMQ : public SegmentTree<T> {
protected:
  T function(T vl, T vr) { return min(vl, vr); }

public:
  RMQ(int n) : SegmentTree<T>(n) {}
};
