#include "graph/edge.hpp"
#include "graph/adjacency_matrix.hpp"
#include "graph/shortest_path.hpp"
#include "graph/count_walk.hpp"
#include "math/mint.hpp"

int main() {
  typedef AdjacencyMatrix<Edge> Graph;
  int n, a, b, m;
  cin >> n >> a >> b >> m;
  --a, --b;
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    graph.addUndirectedEdge(a, b);
  }
  int d = shortestPath(graph, a, b);
  cout << countWalk<Graph, Mint>(graph, d)[a][b] << endl;
}
