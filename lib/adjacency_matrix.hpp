#include "graph.hpp"

template<typename Edge> class AdjacencyMatrix : public Graph<Edge> {
private:
  vector<vector<vector<Edge>>> graph;

public:
  AdjacencyMatrix(int n) : graph(n, vector<vector<Edge>>(n, vector<Edge>())) {}

  int size() const {
    return graph.size();
  }

  vector<Edge> edges(int v) const {
    vector<Edge> res;
    for (const auto& edges : graph[v]) {
      for (const auto& edge : edges) {
        res.emplace_back(edge);
      }
    }
    return res;
  }

  void addEdge(const Edge& edge) {
    graph[edge.from][edge.to].emplace_back(edge);
  }

  void addUndirectedEdge(Edge edge) {
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges(int from, int to) const {
    return graph[from][to];
  }

  int getDegree(int v) const {
    int res = 0;
    for (const auto& edges : graph[v]) res += edges.size();
    return res;
  }
};
