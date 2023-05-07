#include "container/union_find.hpp"
#include "graph/adjacency_list.hpp"

int main() {
  AdjacencyList<LabeledEdge<int>> graph(in);
  auto edges = graph.getAllEdges();
  int q(in);
  Vector<Vector<Tuple<int, int>>> road(200001);
  Vector<Vector<Tuple<int, int>>> query(200001);
  for (const auto &edge : edges) {
    road[edge.label].emplace_back(edge.from, edge.to);
  }
  for (int i = 0; i < q; ++i) {
    int v(in), w(in);
    query[w].emplace_back(i, v - 1);
  }
  Vector<int> result(q);
  UnionFind uf(graph.size());
  for (int year = 200000; year >= 0; --year) {
    for (const auto &[i, v] : query[year]) {
      result[i] = uf.size(v);
    }
    for (const auto &[from, to] : road[year]) {
      uf.unite(from, to);
    }
  }
  result.output();
}
