#pragma once
#include "template.hpp"

template<template<typename Edge> class Graph, typename Edge> class Clique {
private:
  const Graph<Edge> graph;
  
public:
  Clique(const Graph<Edge>& graph) : graph(graph) {}

  void maximal(vector<vector<int>>& cliques, vector<int>& current, vector<int> remains) {
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
      vector<int> next;
      for (int vv : remains) {
        if (!graph.getEdges(v, vv).empty()) next.emplace_back(vv);
      }
      maximal(cliques, current, next);
      current.pop_back();
    }
  }
  
  vector<vector<int>> maximal() {
    vector<vector<int>> cliques;
    vector<int> current, remains;
    for (int i = 0; i < graph.size(); ++i) remains.emplace_back(i);
    maximal(cliques, current, remains);
    return cliques;
  }

  void maximum(vector<int>& maximumClique, vector<int>& current, vector<int> remains) {
    if (maximumClique.size() < current.size()) maximumClique = current;
    int maxSize = maximumClique.size();
    if ((int)current.size() + (int)remains.size() <= maxSize) return;
    if (graph.getDegree(remains[maxSize - current.size()]) < maxSize) return;
    for (int v : remains) {
      current.emplace_back(v);
      vector<int> next;
      for (int vv : remains) {
        if (!graph.getEdges(v, vv).empty()) next.emplace_back(vv);
      }
      maximum(maximumClique, current, next);
      current.pop_back();
    }
  }
  
  vector<int> maximum() {
    vector<pair<int, int>> v;
    for (int i = 0; i < graph.size(); ++i) v.emplace_back(graph.getDegree(i), i);
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    vector<int> maximumClique, current, remains;
    for (int i = 0; i < graph.size(); ++i) remains.emplace_back(v[i].second);
    maximum(maximumClique, current, remains);
    if (maximumClique.empty()) maximumClique.emplace_back(0);
    return maximumClique;
  }
};
