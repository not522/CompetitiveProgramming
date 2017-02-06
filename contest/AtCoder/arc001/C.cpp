#include "n_queens.hpp"

int main() {
  vector<string> v(8);
  for (auto& i : v) cin >> i;
  for (auto s : v) {
    if (count(s.begin(), s.end(), 'Q') > 1) {
      cout << "No Answer" << endl;
      return 0;
    }
  }
  vector<int> u(8);
  for (int i = 0; i < 8; ++i) u[i] = v[i].find('Q');
  NQueens q(8);
  for (auto b : q.solve()) {
    bool ok = true;
    for (int i = 0; i < 8; ++i) {
      if (u[i] == int(string::npos)) continue;
      if (u[i] != b[i]) ok = false;
    }
    if (ok) {
      for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << (b[i] == j ? "Q" : ".");
        cout << endl;
      }
      return 0;
    }
  }
  cout << "No Answer" << endl;
}
