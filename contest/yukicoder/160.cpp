#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"

struct Cost {
  int dist, from;

  constexpr Cost() : dist(0), from(-1) {}

  constexpr Cost(int dist) : dist(dist), from(-1) {}

  constexpr Cost(int dist, int to) : dist(dist), from(to) {}

  Cost operator+(const Cost &cost) const {
    return Cost(dist + cost.dist, cost.from);
  }

  bool operator<(const Cost &cost) const {
    if (dist != cost.dist) {
      return dist < cost.dist;
    }
    return from < cost.from;
  }
};

template <> constexpr Cost inf() { return Cost(inf<int>(), inf<int>()); }

int main() {
  int n(in), m(in), s(in), g(in);
  AdjacencyList<WeightedEdge<Cost>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in), c(in);
    graph.addEdge(a, b, c, a);
    graph.addEdge(b, a, c, b);
  }
  shortestPathTree(graph, g).shortestPathTree.getPath(s).output(" ");
}
