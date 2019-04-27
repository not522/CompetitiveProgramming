#include "template.hpp"

int main() {
  set_bool_name("POSSIBLE", "IMPOSSIBLE");
  int n, m;
  cin >> n >> m;
  set<int> x;
  vector<int> y;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 1) x.emplace(b);
    if (b == n) y.emplace_back(a);
  }
  for (int i : y) {
    if (x.count(i)) {
      cout << true << endl;
      return 0;
    }
  }
  cout << false << endl;
}
