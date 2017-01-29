#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/dfs.hpp"
#include "dp/tree_dp.hpp"

class TreeGraph : public TreeDP<Tree<Edge>, pair<int, bool>> {
private:
  vector<int> h;

  pair<int, bool> visit(int v, const vector<pair<int, bool>>& children) {
    auto f = [](pair<int, bool> p){return p.second;};
    if (h[v] == 0 && none_of(children.begin(), children.end(), f)) return make_pair(0, false);
    auto s = [](int n, pair<int, bool> p){return n + p.first + (p.second ? 2 : 0);};
    return make_pair(accumulate(children.begin(), children.end(), 0, s), true);
  }

public:
  TreeGraph(const Tree<Edge>& tree, const vector<int>& h) : TreeDP(tree), h(h) {}
};

int main() {
  int n, x;
  cin >> n >> x;
  --x;
  vector<int> h(n);
  for (int& i : h) cin >> i;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  auto tree = dfsTree(graph, x);
  TreeGraph treeGraph(tree, h);
  cout << treeGraph.solve(x).first << endl;
}
