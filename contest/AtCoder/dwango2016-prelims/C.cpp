#include "vector.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

struct MyEdge : public WeightedEdge<int> {
  int end, endcost;
  MyEdge(int to = -1, int cost = 0, int end = 0, int endcost = 0) : WeightedEdge<int>(to, cost), end(end), endcost(endcost) {}
};

struct MyState : public DijkstraState<MyEdge> {
  static vector<int> dis;

  MyState(int pos) : DijkstraState<MyEdge>(pos) {}

  MyState(int from, const MyEdge& edge, Cost cost) : DijkstraState<MyEdge>(from, edge, cost) {}

  MyState next(int from, const MyEdge& edge) const {
    return MyState(from, edge, max(cost + edge.cost, edge.endcost + dis[edge.end]));
  }
};

vector<int> MyState::dis;

int main() {
  int n, m, src, dst;
  cin >> n >> m >> src >> dst;
  vector<int> l(m);
  vector<vector<int>> s(m), w(m);
  AdjacencyList<MyEdge> graph(n);
  for (int i = 0; i < m; ++i) {
    cin >> l[i];
    s[i].resize(l[i]);
    w[i].resize(l[i] - 1);
    cin >> s[i] >> w[i];
    int sum = accumulate(w[i]);
    int s1 = sum, s2 = sum;
    for (int j = 0; j < l[i] - 1; ++j) {
      graph[s[i][j + 1]].emplace_back(s[i][j], w[i][j], s[i].back(), s1);
      s1 -= w[i][j];
    }
    for (int j = l[i] - 1; j >= 1; --j) {
      graph[s[i][j - 1]].emplace_back(s[i][j], w[i][j - 1], s[i][0], s2);
      s2 -= w[i][j - 1];
    }
  }
  MyState::dis = shortestPath(graph, dst).dis;
  Dijkstra<AdjacencyList<MyEdge>, false, MyState> dijkstra(graph);
  dijkstra.solve(dst);
  cout << dijkstra.dis[src] << endl;
}
