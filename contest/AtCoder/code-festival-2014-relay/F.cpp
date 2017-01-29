#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "graph/edge.hpp"

class MyBFS : public BFS<AdjacencyList<Edge>> {
private:
  vector<int> degree;

  void push(const BFSState<Edge>& state) {if (degree[state.pos] == 1) que.push(state);}

  void visit(const BFSState<Edge>& state) {
    for (const auto& e : graph.getEdges(state.pos)) --degree[e.to];
    --res;
  }

public:
  int res;

  MyBFS(const AdjacencyList<Edge>& graph) : BFS<AdjacencyList<Edge>>(graph), res(graph.size()) {
    for (int i = 0; i < graph.size(); ++i) degree.emplace_back(graph.getDegree(i));
  }
};

int main() {
  int n;
  cin >> n;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    graph.addUndirectedEdge(x - 1, y - 1);
  }
  vector<int> ones;
  for (int i = 0; i < n; ++i) if (graph.getDegree(i) == 1) ones.emplace_back(i);
  MyBFS bfs(graph);
  bfs.solve(ones);
  cout << bfs.res << endl;
}
