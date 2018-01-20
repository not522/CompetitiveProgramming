#include "math/sat.hpp"

int main() {
  int v, e;
  cin >> v >> e;
  vector<vector<pair<int, bool>>> clauses;
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    for (int j = 0; j < 4; ++j) {
      vector<pair<int, bool>> clause;
      clause.emplace_back(a, j % 2);
      clause.emplace_back(b, j % 2);
      clause.emplace_back(a + v, j / 2);
      clause.emplace_back(b + v, j / 2);
      clauses.emplace_back(clause);
    }
  }
  SatSolver solver(2 * v, clauses);
  solver.solve();
  for (int i = 0; i < 2 * v; ++i) cerr << i << " " << solver.assigns[i] << endl;
  for (int i = 0; i < v; ++i) {
    cout << 2 * solver.assigns[i] + solver.assigns[i + v] + 1 << endl;
  }
}
