#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(m), y(m);
  cin >> x;
  sort(x);
  adjacent_difference(x, y);
  y = subvector(y, 1, m);
  rsort(y);
  cout << x.back() - x[0] - accumulate(subvector(y, 0, n - 1)) << endl;
}
