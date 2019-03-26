#pragma once
#include "tuple.hpp"
#include "vector.hpp"

template<template<typename Edge> class Graph, typename Edge> class Clique {
private:
  const Graph<Edge> graph;

public:
  Clique(const Graph<Edge>& graph) : graph(graph) {}

  void maximal(Vector<Vector<int>>& cliques, Vector<int>& current, Vector<int> remains) {
    if (remains.empty()) {
      for (int i = 0; i < graph.size(); ++i) {
        if (find(current.begin(), current.end(), i) != current.end()) continue;
        if (none_of(current.begin(), current.end(), [this, i](int v){return graph.getEdges(i, v).empty();})) return;
      }
      cliques.emplace_back(current);
      return;
    }
    for (int v : remains) {
      current.emplace_back(v);
      Vector<int> next;
      for (int vv : remains) {
        if (!graph.getEdge(v, vv).isNone()) next.emplace_back(vv);
      }
      maximal(cliques, current, next);
      current.pop_back();
    }
  }

  Vector<Vector<int>> maximal() {
    Vector<Vector<int>> cliques;
    Vector<int> current, remains;
    for (int i = 0; i < graph.size(); ++i) remains.emplace_back(i);
    maximal(cliques, current, remains);
    return cliques;
  }

  void maximum(Vector<int>& maximumClique, Vector<int>& current, Vector<int> remains) {
    if (maximumClique.size() < current.size()) maximumClique = current;
    int maxSize = maximumClique.size();
    if (int(current.size() + remains.size()) <= maxSize) return;
    if (graph.getDegree(remains[maxSize - current.size()]) < maxSize) return;
    for (int v : remains) {
      current.emplace_back(v);
      Vector<int> next;
      for (int vv : remains) {
        if (!graph.getEdge(v, vv).isNone()) next.emplace_back(vv);
      }
      maximum(maximumClique, current, next);
      current.pop_back();
    }
  }

  Vector<int> maximum() {
    Vector<Tuple<int, int>> v;
    for (int i = 0; i < graph.size(); ++i) v.emplace_back(graph.getDegree(i), i);
    v.rsort();
    Vector<int> maximumClique, current, remains;
    for (int i = 0; i < graph.size(); ++i) remains.emplace_back(v[i].get<1>());
    maximum(maximumClique, current, remains);
    if (maximumClique.empty()) maximumClique.emplace_back(0);
    return maximumClique;
  }
};
