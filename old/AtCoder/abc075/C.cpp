#include "graph/adjacency_list.hpp"
#include "graph/lowlink.hpp"

int main() {
  using MyGraph = AdjacencyList<Edge>;
  MyGraph graph;
  cin >> graph;
  cout << LowLink<MyGraph>(graph).bridge().size() << endl;
}
