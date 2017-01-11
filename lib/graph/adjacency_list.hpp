#pragma once
#include "graph/graph.hpp"

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  vector<Edge> getEdges(int from) const {
    return graph[from];
  }

  vector<Edge> getEdges(int from, int to) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }

  int getDegree(int v) const {
    return graph[v].size();
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};
