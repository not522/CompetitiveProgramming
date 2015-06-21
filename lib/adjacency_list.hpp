#include "graph.hpp"

template<typename Edge> class AdjacencyList : public Graph<Edge> {
private:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() {
    return graph.size();
  }

  vector<Edge> edges(int v) {
    return graph[v];
  }
  
  void addEdge(const Edge& edge) {
    graph[edge.from].emplace_back(edge);
  }

  void addUndirectedEdge(Edge edge) {
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges(int from, int to) {
    vector<Edge> res;
    for (const auto& edge : edges(from)) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }

  int getDegree(int v) {
    return graph[v].size();
  }
};
