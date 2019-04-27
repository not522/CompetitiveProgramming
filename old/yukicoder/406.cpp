#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  cin >> x;
  sort(x);
  adjacent_difference(x);
  x = subvector(x, 1, n);
  cout << (max(x) != 0 && max(x) == min(x) ? "YES" : "NO") << endl;
}
