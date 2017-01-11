#include "graph/adjacency_list.hpp"
#include "graph/bfs.hpp"
#include "graph/edge.hpp"

class Shiritori : public BFS<AdjacencyList<Edge>> {
private:
  vector<int> cnt, degree;

  void visit(const BFSState<Edge>& state) {win[state.pos] = state.prv != -1 ? -win[state.prv] : -1;}

  void push(const BFSState<Edge>& state) {
    if (state.prv == -1 || win[state.prv] != -1) {
      if (++cnt[state.pos] < degree[state.pos]) return;
    }
    que.push(state);
  }

public:
  vector<int> win;

  Shiritori(const AdjacencyList<Edge>& graph) : BFS<AdjacencyList<Edge>>(graph), cnt(graph.size()), degree(graph.getIndegree()), win(graph.size()) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<Edge> graph(n);
  set<int> s;
  for (int i = 0; i < m; ++i) {
    int p, q;
    cin >> p >> q;
    --p, --q;
    graph.addEdge(q, p);
    s.insert(p);
  }
  vector<int> from;
  for (int i = 0; i < n; ++i) if (!s.count(i)) from.emplace_back(i);
  Shiritori shiritori(graph);
  shiritori.solve(from);
  switch (shiritori.win[0]) {
  case 1:  cout << "Snuke" << endl; break;
  case -1: cout << "Sothe" << endl; break;
  case 0:  cout << "Draw"  << endl; break;
  }
}
