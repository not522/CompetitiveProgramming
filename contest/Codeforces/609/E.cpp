#include "graph/adjacency_list.hpp"
#include "graph/edge.hpp"
#include "graph/minimum_spanning_tree.hpp"
#include "graph/tree_path_query.hpp"

using MyEdge = WeightedEdge<int>;

class PathMaximumQuery : public TreePathQuery<MyEdge> {
private:
  int init(int v) {return lca.tree.parent[v].cost;}
  int function(int a, int b) {return max(a, b);}

public:
  PathMaximumQuery(const Tree<MyEdge>& tree) : TreePathQuery<MyEdge>(tree, 0) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  AdjacencyList<MyEdge> graph(n);
  vector<int> u(m), v(m), w(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i], --v[i];
    graph.addUndirectedEdge(u[i], v[i], w[i]);
  }
  auto tree = minimumSpanningTree(graph);
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) sum += tree.parent[i].cost;
  auto tpq = PathMaximumQuery(tree);
  for (int i = 0; i < m; ++i) {
    cout << sum + w[i] - tpq.solve(u[i], v[i]) << endl;
  }
}
