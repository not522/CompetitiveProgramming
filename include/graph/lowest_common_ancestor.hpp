#pragma once
#include "graph/tree.hpp"
#include "bit_operation.hpp"

template<typename Edge> class LowerCommonAncestor {
private:
  Vector<int> depth;
  Vector<Vector<int>> ancestor;

public:
  const Tree<Edge> tree;

  LowerCommonAncestor(const Tree<Edge>& tree) : depth(tree.size(), -1), ancestor(tree.size()), tree(tree) {}

  int getDepth(int v) {
    if (depth[v] != -1) return depth[v];
    if (tree.parent[v].to == v) return depth[v] = 0;
    return depth[v] = getDepth(tree.parent[v].to) + 1;
  }

  int getAncestor(int v, int depth) {
    if (depth >= int(ancestor[v].size())) ancestor[v].resize(depth + 1, -1);
    if (ancestor[v][depth] != -1) return ancestor[v][depth];
    if (depth == 0) return ancestor[v][depth] = tree.parent[v].to;
    return ancestor[v][depth] = getAncestor(getAncestor(v, depth - 1), depth - 1);
  }

  int solve(int v1, int v2) {
    int d1 = getDepth(v1);
    int d2 = getDepth(v2);
    if (d1 > d2) {
      swap(v1, v2);
      swap(d1, d2);
    }
    for (int d = d2 - d1; d; d &= d - 1) v2 = getAncestor(v2, least_bit(d));
    if (v1 == v2) return v1;
    for (int i = most_bit(d1); i >= 0; --i) {
      int a1 = getAncestor(v1, i);
      int a2 = getAncestor(v2, i);
      if (a1 != a2) {
        v1 = a1;
        v2 = a2;
      }
    }
    return tree.parent[v1].to;
  }
};
