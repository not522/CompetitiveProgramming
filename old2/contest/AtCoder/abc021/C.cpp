#include "graph/adjacency_matrix.hpp"
#include "graph/count_walk.hpp"
#include "graph/shortest_path.hpp"
#include "math/mint_square_matrix.hpp"

int main() {
  using Graph = AdjacencyMatrix<Edge>;
  int n(in), a(in), b(in), m(in);
  --a, --b;
  Graph graph(in, n, m);
  int d = shortestPath(graph, a, b);
  cout << countWalk<Graph, Mint>(graph, d)[a][b] << endl;
}
