#include "dp/tree_dp.hpp"
#include "graph/graph.hpp"

class Salary : public TreeDP<Tree<Edge>, int> {
private:
  int visit(int v, const Vector<int> &children) {
    (void)v;
    if (children.empty()) {
      return 1;
    }
    auto m = children.minmax();
    return m.get<0>() + m.get<1>() + 1;
  }

public:
  Salary(const Tree<Edge> &tree) : TreeDP(tree) {}
};

int main() {
  int n(in);
  Tree<Edge> tree(n, in);
  Salary salary(tree);
  cout << salary.solve(0) << endl;
}
