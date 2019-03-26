#include "graph/adjacency_matrix.hpp"
#include "graph/clique.hpp"

int main() {
  int n(in), m(in);
  AdjacencyMatrix<Edge> graph(in, n, m);
  Clique<AdjacencyMatrix, Edge> clique(graph);
  cout << clique.maximum().size() << endl;
}
