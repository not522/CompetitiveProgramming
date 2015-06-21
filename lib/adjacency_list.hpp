#include "graph.hpp"

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n = 0) : graph(n) {}

  int size() {
    return graph.size();
  }

  vector<Edge> edges(int v) {
    return graph[v];
  }
  
  void addEdge(const Edge& edge) {
    if (int(graph.size()) <= max(edge.from, edge.to)) graph.resize(max(edge.from, edge.to) + 1);
    graph[edge.from].emplace_back(edge);
  }

  vector<Edge> getEdges(int from, int to) {
    vector<Edge> res;
    for (const auto& edge : edges(from)) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }
};
