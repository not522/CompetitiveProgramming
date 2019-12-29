#include "graph/adjacency_list.hpp"
#include "graph/lowlink.hpp"

int main() {
  AdjacencyList<Edge> graph(in);
  cout << LowLink<AdjacencyList<Edge>>(graph).bridge().size() << endl;
}
