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
  
  template<typename... Args> void addEdge(Args... args) {
    Edge edge(args...);
    graph[edge.from].emplace_back(edge);
  }

  template<typename... Args> void addUndirectedEdge(Args... args) {
    Edge edge(args...);
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges() const {
    vector<Edge> res;
    for (const auto& edges : graph) {
      res.insert(res.end(), edges.begin(), edges.end());
    }
    return res;
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
