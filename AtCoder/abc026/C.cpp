#include "graph/edge.hpp"
#include "graph/tree.hpp"
#include "dp/tree_dp.hpp"

class Salary : public TreeDP<Tree<Edge>, int> {
private:
  int visit(int v, const vector<int>& children) {
    if (children.empty()) return 1;
    auto m = minmax_element(children.begin(), children.end());
    return *m.first + *m.second + 1;
  }

public:
  Salary(const Tree<Edge>& tree) : TreeDP(tree) {}
};

int main() {
  int n;
  cin >> n;
  Tree<Edge> tree(n);
  for (int i = 1; i < n; ++i) {
    int b;
    cin >> b;
    tree.addEdge(i, b - 1);
  }
  Salary salary(tree);
  cout << salary.solve(0) << endl;
}
