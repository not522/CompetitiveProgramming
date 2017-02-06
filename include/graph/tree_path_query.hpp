#pragma once
#include "bit_operation.hpp"
#include "graph/lower_common_ancestor.hpp"

template<typename Edge, typename T = typename Edge::CostType> class TreePathQuery {
private:
  const T DEFAULT;
  vector<vector<T>> mem;

protected:
  LowerCommonAncestor<Edge> lca;

  virtual T init(int v) = 0;
  virtual T function(T a, T b) = 0;

public:
  TreePathQuery(const Tree<Edge>& tree, const T def = numeric_limits<T>::max()) : DEFAULT(def), mem(tree.size()), lca(tree) {}

  T calc(int v, int depth) {
    if (depth >= int(mem[v].size())) mem[v].resize(depth + 1, -1);
    if (depth == -1) return DEFAULT;
    if (mem[v][depth] != -1) return mem[v][depth];
    if (depth == 0) return mem[v][depth] = init(v);
    return mem[v][depth] = function(calc(v, depth - 1), calc(lca.calcAncestor(v, depth - 1), depth - 1));
  }

  T solve(int v1, int v2) {
    int d1 = lca.calcDepth(v1);
    int d2 = lca.calcDepth(v2);
    int da = lca.calcDepth(lca.solve(v1, v2));
    int u1 = v1, u2 = v2;
    for (int d = d1 - da; count_bit(d) > 1; d &= d - 1) u1 = lca.calcAncestor(u1, least_bit(d));
    for (int d = d2 - da; count_bit(d) > 1; d &= d - 1) u2 = lca.calcAncestor(u2, least_bit(d));
    T r1 = function(calc(v1, most_bit(d1 - da)), calc(u1, most_bit(d1 - da)));
    T r2 = function(calc(v2, most_bit(d2 - da)), calc(u2, most_bit(d2 - da)));
    return function(r1, r2);
  }
};
