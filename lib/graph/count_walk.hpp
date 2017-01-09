#pragma once
#include "math/pow.hpp"
#include "math/square_matrix.hpp"

template<typename Graph, typename Integer = long long> SquareMatrix<Integer> countWalk(const Graph& graph, long long n) {
  SquareMatrix<Integer> mat(graph.size());
  for (int from = 0; from < graph.size(); ++from) {
    for (int to = 0; to < graph.size(); ++to) {
      mat[from][to] = graph.getEdges(from, to).size();
    }
  }
  return pow(mat, n);
}
