#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

struct MyState : public DijkstraState<WeightedEdge<int64_t>> {
  static vector<int64_t> a, b, c;

  MyState(const int pos) : DijkstraState<WeightedEdge<int64_t>>(pos) {}

  MyState(const int from, const WeightedEdge<int64_t>& edge, int64_t cost) : DijkstraState<WeightedEdge<int64_t>>(from, edge, cost) {}

  MyState next(const int from, const WeightedEdge<int64_t>& edge) const {
    int64_t k = cost;
    if (k < c[from]) {
      k = c[from];
    } else {
      if ((k - c[from]) % (a[from] + b[from]) >= a[from]) {
        k += (a[from] + b[from]) - (k - c[from]) % (a[from] + b[from]);
      }
    }
    return MyState(from, edge, k + edge.cost);
  }
};

vector<int64_t> MyState::a;
vector<int64_t> MyState::b;
vector<int64_t> MyState::c;

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<int64_t> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
  MyState::a = a;
  MyState::b = b;
  MyState::c = c;
  AdjacencyList<WeightedEdge<int64_t>> graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    graph.addUndirectedEdge(x - 1, y - 1, t);
  }
  auto dijkstra = Dijkstra<AdjacencyList<WeightedEdge<int64_t>>, false, MyState>(graph);
  dijkstra.solve(s - 1);
  cout << dijkstra.dis[d - 1] << endl;
}
