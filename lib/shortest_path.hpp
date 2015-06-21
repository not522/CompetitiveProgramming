#include "graph.hpp"

template<typename Edge> class ShortestPath : public Graph<Edge> {
private:
  typedef __typeof(Edge::cost) Cost;

  struct State {
    int pos;
    Cost cost;
    bool operator<(const State& state) const {return cost > state.cost;}
  };

public:
  const Cost INF;

  vector<Cost> dist;

  ShortestPath(const Graph<Edge>& graph) : Graph<Edge>(graph), INF(numeric_limits<Cost>::max()) {}
  
  void run (int from) {
    priority_queue<State> que;
    que.push((State){from, 0});
    dist.resize(this->graph.size(), INF);
    
    while (!que.empty()) {
      State now = que.top();
      que.pop();
      if (dist[now.pos] <= now.cost) continue;
      dist[now.pos] = now.cost;
      for (const Edge& edge : this->graph[now.pos]) {
        if (dist[edge.to] < now.cost + edge.cost) continue;
        que.push((State){edge.to, now.cost + edge.cost});
      }
    }
  }
};
