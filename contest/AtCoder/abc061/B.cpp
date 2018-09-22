#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ++c[a - 1];
    ++c[b - 1];
  }
  cout << c;
}
