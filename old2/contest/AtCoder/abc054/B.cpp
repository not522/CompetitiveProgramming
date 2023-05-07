#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<String> a(n, in), b(m, in);
  for (int i = 0; i <= n - m; ++i) {
    for (int j = 0; j <= n - m; ++j) {
      bool f = true;
      for (int y = 0; y < m; ++y) {
        if (a[i + y].substr(j, m) != b[y]) {
          f = false;
        }
      }
      if (f) {
        cout << true << endl;
        return 0;
      }
    }
  }
  cout << false << endl;
}
