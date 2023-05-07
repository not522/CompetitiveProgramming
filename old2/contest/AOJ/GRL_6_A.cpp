#include "graph/max_flow.hpp"

int main() {
  int v(in), e(in);
  ResidualGraph<ResidualEdge<int>> graph(in, v, e, false, false);
  cout << maxFlow(graph, 0, v - 1) << endl;
}
