#pragma once
#include "math/pow.hpp"
#include "math/square_matrix.hpp"

template <typename Graph, typename Integer = int64_t>
SquareMatrix<Integer> countWalk(const Graph &graph, int64_t n) {
  SquareMatrix<Integer> mat(graph.size());
  for (int from = 0; from < graph.size(); ++from) {
    for (int to = 0; to < graph.size(); ++to) {
      mat[from][to] = graph.getEdge(from, to).isNone() ? 0 : 1;
    }
  }
  return pow(mat, n);
}
