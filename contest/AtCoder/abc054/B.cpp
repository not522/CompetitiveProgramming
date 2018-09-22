#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  cin >> a >> b;
  for (int i = 0; i <= n - m; ++i) {
    for (int j = 0; j <= n - m; ++j) {
      bool f = true;
      for (int y = 0; y < m; ++y) {
        if (a[i + y].substr(j, m) != b[y]) f = false;
      }
      if (f) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
