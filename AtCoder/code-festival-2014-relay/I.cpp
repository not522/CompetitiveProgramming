#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/shortest_path.hpp"

struct MyState : public DijkstraState<WeightedEdge<long long>> {
  static vector<long long> a, b, c;

  MyState(const int pos) : DijkstraState<WeightedEdge<long long>>(pos) {}

  MyState(const int from, const WeightedEdge<long long>& edge, long long cost) : DijkstraState<WeightedEdge<long long>>(from, edge, cost) {}

  MyState next(const int from, const WeightedEdge<long long>& edge) const {
    long long k = cost;
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

vector<long long> MyState::a;
vector<long long> MyState::b;
vector<long long> MyState::c;

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<long long> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
  MyState::a = a;
  MyState::b = b;
  MyState::c = c;
  AdjacencyList<WeightedEdge<long long>> graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    graph.addUndirectedEdge(x - 1, y - 1, t);
  }
  auto dijkstra = Dijkstra<AdjacencyList<WeightedEdge<long long>>, false, MyState>(graph);
  dijkstra.solve(s - 1);
  cout << dijkstra.dis[d - 1] << endl;
}
