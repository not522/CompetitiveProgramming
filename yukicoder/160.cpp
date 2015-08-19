#include "ordered.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "string/to_string.hpp"

struct Cost : public Ordered<Cost> {
  int dist, from;

  constexpr Cost() : dist(0), from(-1) {}

  constexpr Cost(int dist) : dist(dist), from(-1) {}

  constexpr Cost(int dist, int to) : dist(dist), from(to) {}

  Cost operator+(const Cost& cost) const {
    return Cost(dist + cost.dist, cost.from);
  }

  bool operator<(const Cost& cost) const {
    if (dist != cost.dist) return dist < cost.dist;
    return from < cost.from;
  }
};

namespace std {
  template<> constexpr Cost numeric_limits<Cost>::max() {
    return Cost(numeric_limits<int>::max(), numeric_limits<int>::max());
  }
}

struct Edge {
  typedef Cost CostType;
  int from, to;
  Cost cost;
  Edge(int from, int to) : from(from), to(to), cost(0, from) {};
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost, from) {};
};

int main() {
  int n, m, s, g;
  cin >> n >> m >> s >> g;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.addEdge(a, b, c);
    graph.addEdge(b, a, c);
  }
  cout << to_string(shortestPathTree(graph, g).shortestPathTree.getPath(s)) << endl;
}
