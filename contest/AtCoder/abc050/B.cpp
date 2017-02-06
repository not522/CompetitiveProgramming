#include "vector.hpp"

int main() {
  int n, m;
  cin >> n;
  vector<int> t(n);
  cin >> t >> m;
  auto s = accumulate(t);
  for (int i = 0; i < m; ++i) {
    int p, x;
    cin >> p >> x;
    cout << s - t[p - 1] + x << endl;
  }
}
